#include"DxLib.h"
#include"Input.h"
#include"Player.h"
#include"EnemyMng.h"
#include"Chore.h"
#include"Value.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	SetGraphMode(2160, 1440, 32);

	{
		SetWindowSizeChangeEnableFlag(TRUE);
		SetWindowSizeExtendRate(0.6);
		ChangeWindowMode(TRUE);
	}


	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);

	XINPUT_STATE input;

	int Key[10] = { 0 };

	int flag = 0;
	int selectFlag = 0;	//0:play,1:manual,2:credit
	int count = 0;
	int keep_count = 0;
	Player player;
	InputInitialize(Key);
	player.Initialize();
	EnemyMngInitialize();
	SystemInitialize();
	InputFile("kanuma2017.txt");

	SetBack(1);
	PlayBGM();

	flag = 0;
	int down = 0;
	int up = 0;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen()) {

		GetJoypadXInputState(DX_INPUT_PAD1, &input);
		//InputUpdata(input, Key);
		InputUpdata(Key);
		//PrintInput(Key);

		UpdataBack(count);
		DrawBack();


		switch (flag) {
		case 0://OP
			DrawOP();
			DrawData();
			if (THUMB_Y >= 80) down++; else down = 0;
			if (THUMB_Y <= -80) up++; else up = 0;

			if (down == 1) {
				PlayMove();
				if (selectFlag == 3) selectFlag = 0;
				else selectFlag++;
			}
			if (up == 1) {
				PlayMove();
				if (selectFlag == 0) selectFlag = 3;
				else selectFlag--;
			}
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
			count = 0;
			player.Set();
			EnemyMngInitialize(1);
			ChoreSet();
			flag = 8;
			break;
		case 2://playing
			//EnemyMngSet(levelFlag, count, girl.GetCenter());
			//player.Updata(count, Key);
			//girl.Updata(count, player.PriJump);
			//EnemyMngUpdata(count);

			//EnemyMngJudge(&player, &girl, count, ScorePass(), levelFlag);

			//if (girl.GetHP() <= 0) {
			//	flag = 3;
			//	girl.SetWalk();
			//	SetLoser(levelFlag, count);
			//}
			//if (levelFlag == 0 && count >= NORMAL_COUNT) {
			//	flag = 4;
			//	girl.SetWalk();
			//	SetWinner(levelFlag, count, ScorePass());
			//}
			//if (levelFlag == 1 && count >= HARD_COUNT) {
			//	girl.SetWalk();
			//	flag = 4;
			//	SetWinner(levelFlag, count, ScorePass());
			//}
			//if (PAUSE == 1) flag = 7;

			//EnemyMngDraw();
			//girl.Draw();
			//player.Draw();
			////DrawLine(0, GROUND_HEIGHT, DISP_WIDTH, GROUND_HEIGHT, RED, FALSE);
			////DrawLine(0, BIRD_HIGH, DISP_WIDTH, BIRD_HIGH, RED, FALSE);

			//DrawChore(count, girl.GetHP(), levelFlag);
			break;
		case 3://gameover
			/*EnemyMngUpdata(count);
			EnemyMngDraw();

			girl.Draw();
			player.Draw();
			DrawChore(count, girl.GetHP(), levelFlag);
			if (LoserUpdata(count))
				if (B == 1)
					flag = 0;*/
			break;
		case 4://gameclear
			/*player.Updata(count, Key);
			girl.Updata(count, player.PriJump);
			girl.Draw();
			player.Draw();
			if (WinnerUpdata(count))
				if (B == 1)
					flag = 0;
			DrawChore(count, girl.GetHP(), levelFlag);
			break;*/
		case 5://マニュアル
			   /*if (B == 1)
			   PlayChoice;*/
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
			DrawPause(count);
			count--;
			if (B == 1) flag = 2;
			if (A == 1) flag = 0;
			break;
		default:
			break;
		}

		count++;
		if (CheckHitKey(KEY_INPUT_DELETE)) break;
		//FpsTimeFanction();
		ScreenFlip();
	}

	UpdataFile("kanuma2017.txt", 0, 0);
	DxLib_End();

	return 0;
}