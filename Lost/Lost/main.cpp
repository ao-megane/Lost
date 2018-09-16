#include"DxLib.h"
#include"Input.h"
#include"Player.h"
#include"EnemyMng.h"
#include"Value.h"
#include"Chore.h"
#include"Key.h"
#include"Color.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetGraphMode(2160, 1440, 32);

	{
		SetWindowSizeChangeEnableFlag(TRUE);
		SetWindowSizeExtendRate(0.6);
		ChangeWindowMode(TRUE);
		SetBackgroundColor(0, 0, 0);
	}

	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	XINPUT_STATE input;
	int Key[20] = { 0 };

	int flag = 0;
	int selectFlag = 0;	//0:play,1:manual,2:credit
	int count = 0;
	int keepCount = 0;
	Player player;
	
	InputInitialize(Key);
	player.Initialize();
	KeyInitialize();
	SetRand();
	
	EnemyMngInitialize();
	SystemInitialize();
	ColorMngInitialize();
	//InputFile("kanuma2017.txt");

	PlayTitleBGM();

	flag = 0;
	int Winner = 0;
	int Loser = 0;
	int down = 0;
	int up = 0;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		InputUpdata(input, Key);

		switch (flag) {
		case 0://OP
			DrawOP(count);
			//DrawData();
			
			if (THUMB_Y >= 80) down++; else down = 0;
			if (THUMB_Y <= -80) up++; else up = 0;

			if (Y > 0) DrawFormatString(0, 0, BLACK, "ClearRate:%f,Winner:%d,Loser:%d", (double)Winner / (double)(Winner + Loser), Winner, Loser);

			if (down == 1) {
				PlayMove();
				if (selectFlag == 2) selectFlag = 0;
				else selectFlag++;
			}
			if (up == 1) {
				PlayMove();
				if (selectFlag == 0) selectFlag = 2;
				else selectFlag--;
			}
			DrawTitleSentence(selectFlag);
			if (B == 1) {
				PlayChoice();
				switch (selectFlag)
				{
				case 0://play
					flag = 1;
					break;
				case 1://manual
					flag = 5;
					break;
				case 2://credit
					flag = 6;
					break;
				default:
					break;
				}
			}
			break;
		case 1://Loading
			yesBGM();
			yesESounds();
			yesPSounds();
			yesKeySounds();
			count = 0;
			keepCount = 0;
			player.Set();
			SetKeyPosi();
			EnemyMngSet();
			flag = 8;
			break;
		case 2://playing
			player.Updata(Key,0,count);
			if (player.GetFloor() == GetKeyFloor()) {
				if (player.GetCircle() & GetKeyCircle() && !player.GetKeyflag()) {
					player.keyGet();
					PlayKeyPickup();
				}
			}
			if (player.GetKeyflag() && player.GetFloor() == 1 && GetRock().IsHitCircle(player.GetCircle(), GetFloor1SoftHandle())) {
				//クリア
				flag = 4;
				Winner++;
				keepCount = count;
				PlayKeyUnlock();
			}
			switch (EnemyMngUpdata(player.GetCircle(), player.GetFloor(),count,Getpsound())) {//son,daughter,husband,madamの順
			case 1:
				if (!player.isArm()) {
					flag = 3;
					Loser++;
					keepCount = count;
					break;
				}
				player.LostArm();
				player.Reborn();
				EnemyMngSet();
				keepCount = count;
				break;
			case 2:
				if (!player.isEar()) {
					flag = 3;
					Loser++;
					keepCount = count;
					break;
				}
				player.LostEar();
				player.Reborn();
				EnemyMngSet();
				keepCount = count;
				break;
			case 3:
				player.LostEye();
				player.Reborn();
				EnemyMngSet();
				keepCount = count;
				break;
			case 4:
				player.LostLeg();
				player.Reborn();
				EnemyMngSet();
				keepCount = count;
				break;
			default:
				break;
			}
			if (!player.isEar()) {//両耳なくなったら
				noBGM();
				noESounds();
				//noPSounds();
				noKeySounds();
			}

			if (player.isGameOver()) {
				keepCount = count;
				flag = 3;
				Loser++;
			}
			
			if (PAUSE == 1 || RIGHT == 1) flag = 7;

			DrawBack(player.GetFloor(), player.GetCircle().GetDot());

			player.Draw();
			if (!player.GetKeyflag()) {
				KeyDraw(player.GetDot(), player.GetFloor());
			}

			EnemyMngDraw(player.GetDot(), player.GetFloor());
			
			DrawWalls(player.GetFloor(),player.GetDot());

			player.DrawMask();

			EnemyMngSoundDraw(player.GetCircle(), count, player.GetEarflag());
			player.SoundDraw(count);

			player.UIDraw(count);
			DrawTime(count);

			DrawWhite(count,keepCount);

			//DrawFormatString(200, 80, RED, "keepCount:%d", keepCount);

			//DrawLine(0, GROUND_HEIGHT, DISP_WIDTH, GROUND_HEIGHT, RED, FALSE);
			//DrawLine(0, BIRD_HIGH, DISP_WIDTH, BIRD_HIGH, RED, FALSE);

			//DrawChore();
			break;
		case 3://gameover
			DrawGameOverBord(count - keepCount);
			if (count - keepCount > 180) {
				flag = 0;
				PlayTitleBGM();
			}
			break;
		case 4://gameclear
			DrawClearBord(count - keepCount);
			if (count - keepCount > 180) {
				flag = 0;
				PlayTitleBGM();
			}
			break;
		case 5://マニュアル
			if (B == 1)
				PlayChoice();
			if (DrawManual(B)) {
				flag = 0;
				count = 0;
			}
			break;
		case 6://クレジット
			DrawCredit();
			if (B == 1) {
				PlayChoice();
				flag = 0;
			}
			break;
		case 7://ポーズ
			DrawPause();
			player.UIDraw(count);
			count--;
			if (B == 1) flag = 2;
			if (A == 1) {
				flag = 0;
				PlayTitleBGM();
			}
			break;
		case 8://ゲーム開始前のマニュアル
			if (B == 1)
				PlayChoice();
			if (DrawManual(B)) {
				flag = 2;
				count = 0;
				PlaynormalBGM();
			}
			break;

		default:
			break;
		}

		count++;
		if (CheckHitKey(KEY_INPUT_DELETE)) break;

		//PrintInput(Key);
		//FpsTimeFanction();
		ScreenFlip();
	}

	//UpdataFile("kanuma2017.txt", 0, 0);
	DxLib_End();

	return 0;
}