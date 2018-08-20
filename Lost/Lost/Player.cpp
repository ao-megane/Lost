#include"DxLib.h"
#include"Player.h"
#include"Value.h"
#include"Chore.h"
#include"EnemyMng.h"
#include"Color.h"
#include"Sound.h"

int normalImage;
int larmImage;
int maskEye;
int maskLight;
int maskEar;
int maskRight;
int maskLeft;
int PWalk[8];
int PWalkimage[12];
int PWalkUp[3];
int PWalkDown[3];
int PWalkRight[3];
int PWalkLeft[3];
int Batu;
int haveKey;
int PUI;
Dot center;

int Player::Initialize() {	//複数プレイヤーならもっと丁寧にやること
	LoadDivGraph("images/player/player.png", 12, 3, 4, 32, 32, PWalkimage);
	PWalkDown[0] = PWalkimage[0];
	PWalkDown[1] = PWalkimage[1];
	PWalkDown[2] = PWalkimage[2];
	PWalkLeft[0] = PWalkimage[3];
	PWalkLeft[1] = PWalkimage[4];
	PWalkLeft[2] = PWalkimage[5];
	PWalkRight[0] = PWalkimage[6];
	PWalkRight[1] = PWalkimage[7];
	PWalkRight[2] = PWalkimage[8];
	PWalkUp[0] = PWalkimage[9];
	PWalkUp[1] = PWalkimage[10];
	PWalkUp[2] = PWalkimage[11];
	animeNum = 1;

	normalImage = LoadGraph("images/player/normal.png");

	maskEye = LoadGraph("images/player/masks/eye_s.png");
	maskLight = LoadGraph("images/player/masks/light_l_s.png");

	maskEar = LoadGraph("images/player/masks/ear.png");
	maskRight = LoadGraph("images/player/masks/right.png");
	maskLeft= LoadGraph("images/player/masks/left.png");

	Batu = LoadGraph("images/player/UI/batsu.png");
	haveKey = LoadGraph("images/player/UI/havekey.png");
	PUI = LoadGraph("images/player/UI/UI.png");

	PWalk[0] = LoadSoundMem("sounds/player/1.wav");
	PWalk[1] = LoadSoundMem("sounds/player/2.wav");
	PWalk[2] = LoadSoundMem("sounds/player/3.wav");
	PWalk[3] = LoadSoundMem("sounds/player/4.wav");
	PWalk[4] = LoadSoundMem("sounds/player/5.wav");
	PWalk[5] = LoadSoundMem("sounds/player/6.wav");
	PWalk[6] = LoadSoundMem("sounds/player/7.wav");
	PWalk[7] = LoadSoundMem("sounds/player/8.wav");

	SetPimage(PWalkDown[1]);
	move.Set(0, 0);
	SetFloor(4);
	center.Set(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0);
	return 0;
}

int Player::Set() {
	player.Set(P_REBORN_X, P_REBORN_Y, P_SIZE, 0);
	SetFloor(4);
	bodyClock = 0;
	rEye = true;
	lEye = true;
	rArm = true;
	lArm = true;
	rEar = true;
	lEar = true;
	rLeg = true;
	lLeg = true;
	havekey = false;
	Speed = P_HALF_SPEED;
	move.Set(0, 0);

	return 0;
}
int Player::LostArm() {
	if (GetRand() % 2) {
		if (lArm)
			lArm = false;
		else rArm = false;
	}
	else {
		if (rArm)
			rArm = false;
		else rArm = false;
	}
	return 0;
}
int Player::LostEar() {
	if (GetRand() % 2) {
		if (lEar)
			lEar = false;
		else rEar = false;
	}
	else {
		if (rEar)
			rEar = false;
		else rEar = false;
	}
	return 0;
}
int Player::LostEye() {
	if (GetRand() % 2) {
		if (lEye)
			lEye = false;
		else rEye = false;
	}
	else {
		if (rEye)
			rEye = false;
		else rEye = false;
	}
	return 0;
}
int Player::LostLeg() {
	if (GetRand() % 2) {
		if (lLeg)
			lLeg = false;
		else rLeg = false;
	}
	else {
		if (rLeg)
			rLeg = false;
		else rLeg = false;
	}
	return 0;
}


int Player::Reborn() {
	player.Set(P_REBORN_X, P_REBORN_Y, P_SIZE, 0);
	SetFloor(4);
	move.Set(0, 0);
	return 0;
}

int Player::UpdataMove(double a, double b) {
	
	move.Setx(a);
	move.Sety(b);
	return 0;
}

int Player::GetFloor() {
	return floor;
}
int Player::SetFloor(int a) {
	floor = a;
	return 0;
}

int Player::Updata(int Key[], int flag) {
	if (LEFT > 0) {
			SetSpeed(P_FULL_SPEED);
	}
	else {
		SetSpeed(P_HALF_SPEED);
	}
	if (!lLeg || !rLeg) {//片足なければ
		SetSpeed(GetSpeed() * 2.0 / 3.0);
	}

	if (!lArm)
		Pimage = larmImage;
	else
		Pimage = normalImage;

	//DrawFormatString(0, 60, RED, "%d", WALL);
	//DrawFormatString(0, 80, RED, "%d", GetPixelPalCodeSoftImage(GetNowFloorSoftHandle(), player.GetDot().Getx(), player.GetDot().Gety()));

	UpdataMove(THUMB_X * GetSpeed() / 100.0, THUMB_Y * GetSpeed() / 100.0);

	if (!(GetMove().Getx() == 0 && GetMove().Gety() == 0)){ //移動してれば
		player.SetDir(CalcDir(GetMove()));
		bodyClock++;
		if (bodyClock >= P_CLOCK) bodyClock = 0;
		if (LEFT > 0) {
			if (bodyClock == 0 || bodyClock == P_CLOCK/2) {
				PlayPWalk();

			}
		}
		else {
			if (bodyClock == 0) {
				PlayPWalk();
			}
		}
		if (LEFT > 0) {
			if (bodyClock == 0) {
				animeNum = 1;
			}
			else if (bodyClock == 4) {
				animeNum = 2;
			}
			else if (bodyClock == 7) {
				animeNum = 0;
			}
			else if (bodyClock == 10) {
				animeNum = 1;
			}
			else if (bodyClock == 14) {
				animeNum = 2;
			}
			else if (bodyClock == 17) {
				animeNum = 0;
			}
		}
		else {
			if (bodyClock == 0) {
				animeNum = 1;
			}
			else if(bodyClock == 8){
				animeNum = 2;
			}
			else if(bodyClock == 14) {
				animeNum = 0;
			}
		}
	}
	if (player.GetDir() <= PI / 4.0 || player.GetDir() >= PI * 7.0 / 4.0) {
		Pimage = PWalkRight[animeNum];
	}
	else if(player.GetDir() >= PI / 4.0 && player.GetDir() <= PI * 3.0 / 4.0) {
		Pimage = PWalkUp[animeNum];
	}
	else if (player.GetDir() >= PI * 3.0 / 4.0 && player.GetDir() <= PI * 5.0 / 4.0) {
		Pimage = PWalkLeft[animeNum];
	}
	else if (player.GetDir() >= PI * 5.0 / 4.0 && player.GetDir() <= PI * 7.0 / 4.0) {
		Pimage = PWalkDown[animeNum];
	}

	if (floor == 4) {	//2階にいるとき
		if (!lArm) {//左手がないのに
			if (GetDoor().IsHitMoving(player, GetFloor2SoftHandle())) {	//ドアにぶつかれば
				PlayerMoveInColor(&player, GetMove());
				return 0;
			}
		}
		if (GetWall().IsHitMoving(player, GetFloor2SoftHandle())) {	//壁にぶつかれば
			PlayerMoveInColor(&player, GetMove());
			return 0;
		}
		if (GetHighstep().IsHitCircle(player, GetFloor2SoftHandle())) {	//2階の階段にいるとき
			SetFloor(3);
			return 0;
		}
	}
	else if (floor == 3) {
		//if (Wall.IsHitMoving(player, GetFloor2SoftHandle()) || Wall.IsHitMoving(player, GetFloor1SoftHandle())) {	//壁にぶつかれば
		//	PlayerMoveInColor(&player, GetMove());
		//	return 0;
		//}
		if (GetFloor2().IsHitCircle(player, GetFloor2SoftHandle())) {
			SetFloor(4);
			return 0;
		}
		if (GetLowstep().IsHitCircle(player, GetFloor1SoftHandle())) {
			SetFloor(2);
			return 0;
		}
		if (GetWall().IsHitMoving(player, GetStepSoftHandle())) {	//壁にぶつかれば
			PlayerMoveInColor(&player, GetMove());
			return 0;
		}
	}
	else if (floor == 2) {
		//if (Wall.IsHitMoving(player, GetFloor2SoftHandle()) || Wall.IsHitMoving(player, GetFloor1SoftHandle())) {	//壁にぶつかれば
		//	PlayerMoveInColor(&player, GetMove());
		//	return 0;
		//}
		if (GetFloor1().IsHitCircle(player, GetFloor1SoftHandle())) {
			SetFloor(1);
			return 0;
		}
		if (GetHighstep().IsHitCircle(player, GetFloor2SoftHandle())) {
			SetFloor(3);
			return 0;
		}
		if (GetWall().IsHitMoving(player, GetStepSoftHandle())) {	//壁にぶつかれば
			PlayerMoveInColor(&player, GetMove());
			return 0;
		}
	}
	else if (floor == 1) {	//1階にいるとき
		if (!lArm) {
			if (GetDoor().IsHitMoving(player, GetFloor1SoftHandle())) {	//ドアにぶつかれば
				PlayerMoveInColor(&player, GetMove());
				return 0;
			}
		}
		if (GetWall().IsHitMoving(player, GetFloor1SoftHandle())) {	//壁にぶつかれば
			PlayerMoveInColor(&player, GetMove());
			return 0;
		}
		if (!havekey) {
			if (GetRock().IsHitMoving(player, GetFloor1SoftHandle())) {	//鍵付きのドアにぶつかれば
				PlayerMoveInColor(&player, GetMove());
				return 0;
			}
		}
		if (GetLowstep().IsHitCircle(player, GetFloor1SoftHandle())) {	//2階の階段にいるとき
			SetFloor(2);
			return 0;
		}
	}

	player.Move(GetMove());

	return 0;
}

Dot decoi[4];
int Player::Draw() {//ここも大変、特にマスク処理 ←　マスクは画像の上書きで行く，とりあえず全体表示をしっかり
	/*decoi[0].Setx(DISP_WIDTH / 2.0 - P_SIZE);
	decoi[0].Sety(DISP_HEIGHT / 2.0 - P_SIZE);
	decoi[0] = RotateDot(player.GetDir(), decoi[0], center);
	decoi[1].Setx(DISP_WIDTH / 2.0 + P_SIZE);
	decoi[1].Sety(DISP_HEIGHT / 2.0 - P_SIZE);
	decoi[1] = RotateDot(player.GetDir(), decoi[1], center);
	decoi[2].Setx(DISP_WIDTH / 2.0 + P_SIZE);
	decoi[2].Sety(DISP_HEIGHT / 2.0 + P_SIZE);
	decoi[2] = RotateDot(player.GetDir(), decoi[2], center);
	decoi[3].Setx(DISP_WIDTH / 2.0 - P_SIZE);
	decoi[3].Sety(DISP_HEIGHT / 2.0 + P_SIZE);
	decoi[3] = RotateDot(player.GetDir(), decoi[3], center);
	DrawModiGraph(decoi[0].Getx(),decoi[0].Gety(), decoi[1].Getx(), decoi[1].Gety(), 
		decoi[2].Getx(), decoi[2].Gety(), decoi[3].Getx(), decoi[3].Gety(), Pimage, true);*/

	DrawModiGraph(
		DISP_WIDTH / 2.0 - player.GetRadius(), DISP_HEIGHT / 2.0 - player.GetRadius(),
		DISP_WIDTH / 2.0 + player.GetRadius(), DISP_HEIGHT / 2.0 - player.GetRadius(),
		DISP_WIDTH / 2.0 + player.GetRadius(), DISP_HEIGHT / 2.0 + player.GetRadius(),
		DISP_WIDTH / 2.0 - player.GetRadius(), DISP_HEIGHT / 2.0 + player.GetRadius(),
		Pimage, true
	);

	//DrawFormatString(300, 0, RED, "PLAYER DRAW");
	//DrawFormatString(300, 20, RED, "dir:%f", player.GetDir() * 180 / PI);
	//DrawFormatString(300, 20, RED, "floor:%d", GetFloor());
	//DrawFormatString(300, 20, RED, "bodyclock:%d", bodyClock);
	//DrawFormatString(400, 20, RED, "(%d,%d)", player.Getx(), player.Gety());

	return 0;
}
int Player::DrawMask(){
	decoi[0].Setx(center.Getx() - MASK_WIDTH / 2.0);
	decoi[0].Sety(center.Gety() - MASK_WIDTH / 2.0);
	decoi[0] = RotateDot(player.GetDir(), decoi[0], center);

	decoi[1].Setx(center.Getx() + MASK_WIDTH / 2.0);
	decoi[1].Sety(center.Gety() - MASK_WIDTH / 2.0);
	decoi[1] = RotateDot(player.GetDir(), decoi[1], center);

	decoi[2].Setx(center.Getx() + MASK_WIDTH / 2.0);
	decoi[2].Sety(center.Gety() + MASK_WIDTH / 2.0);
	decoi[2] = RotateDot(player.GetDir(), decoi[2], center);

	decoi[3].Setx(center.Getx() - MASK_WIDTH / 2.0);
	decoi[3].Sety(center.Gety() + MASK_WIDTH / 2.0);
	decoi[3] = RotateDot(player.GetDir(), decoi[3], center);

	if (rArm) {	//ライトがあって
		DrawModiGraph(decoi[0].Getx(), decoi[0].Gety(), decoi[1].Getx(), decoi[1].Gety(),
			decoi[2].Getx(), decoi[2].Gety(), decoi[3].Getx(), decoi[3].Gety(), maskLight, true);
	}
	else {
		DrawModiGraph(decoi[0].Getx(), decoi[0].Gety(), decoi[1].Getx(), decoi[1].Gety(),
			decoi[2].Getx(), decoi[2].Gety(), decoi[3].Getx(), decoi[3].Gety(), maskEye, true);
	}
	if (!lEye) {	//左目がなければ
		DrawModiGraph(decoi[0].Getx(), decoi[0].Gety(), decoi[1].Getx(), decoi[1].Gety(),
			decoi[2].Getx(), decoi[2].Gety(), decoi[3].Getx(), decoi[3].Gety(), maskRight,true);
	}
	if (!rEye) {	//右目がなければ
		DrawModiGraph(decoi[0].Getx(), decoi[0].Gety(), decoi[1].Getx(), decoi[1].Gety(),
			decoi[2].Getx(), decoi[2].Gety(), decoi[3].Getx(), decoi[3].Gety(), maskLeft, true);
	}
	return 0;
}
int Player::UIDraw(int count) {
	DrawModiGraph(0, 0, DISP_WIDTH, 0, DISP_WIDTH, DISP_HEIGHT, 0, DISP_HEIGHT, PUI, true);
	if (!rEye) {
		DrawModiGraph(
			UI_POSI[0] - BATSU_SIZE / 2.0, UI_POSI[1] - BATSU_SIZE / 2.0,
			UI_POSI[0] + BATSU_SIZE / 2.0, UI_POSI[1] - BATSU_SIZE / 2.0,
			UI_POSI[0] + BATSU_SIZE / 2.0, UI_POSI[1] + BATSU_SIZE / 2.0,
			UI_POSI[0] - BATSU_SIZE / 2.0, UI_POSI[1] + BATSU_SIZE / 2.0
			, Batu, true);
	}
	if (!lEye) {
		DrawModiGraph(
			UI_POSI[2] - BATSU_SIZE / 2.0, UI_POSI[3] -BATSU_SIZE / 2.0,
			UI_POSI[2] + BATSU_SIZE / 2.0, UI_POSI[3] -BATSU_SIZE / 2.0,
			UI_POSI[2] + BATSU_SIZE / 2.0, UI_POSI[3] +BATSU_SIZE / 2.0,
			UI_POSI[2] - BATSU_SIZE / 2.0, UI_POSI[3] +BATSU_SIZE / 2.0
			, Batu, true);
	}
	if (!rEar) {
		DrawModiGraph(
			UI_POSI[4] -BATSU_SIZE / 2.0, UI_POSI[5] -BATSU_SIZE / 2.0,
			UI_POSI[4] +BATSU_SIZE / 2.0, UI_POSI[5] -BATSU_SIZE / 2.0,
			UI_POSI[4] +BATSU_SIZE / 2.0, UI_POSI[5] +BATSU_SIZE / 2.0,
			UI_POSI[4] -BATSU_SIZE / 2.0, UI_POSI[5] +BATSU_SIZE / 2.0
			, Batu, true);
	}
	if (!lEar) {
		DrawModiGraph(
			UI_POSI[6] -BATSU_SIZE / 2.0, UI_POSI[7] -BATSU_SIZE / 2.0,
			UI_POSI[6] +BATSU_SIZE / 2.0, UI_POSI[7] -BATSU_SIZE / 2.0,
			UI_POSI[6] +BATSU_SIZE / 2.0, UI_POSI[7] +BATSU_SIZE / 2.0,
			UI_POSI[6] -BATSU_SIZE / 2.0, UI_POSI[7] +BATSU_SIZE / 2.0
			, Batu, true);
	}
	if (!rArm) {
		DrawModiGraph(
			UI_POSI[8] -BATSU_SIZE / 2.0, UI_POSI[9] -BATSU_SIZE / 2.0,
			UI_POSI[8] +BATSU_SIZE / 2.0, UI_POSI[9] -BATSU_SIZE / 2.0,
			UI_POSI[8] +BATSU_SIZE / 2.0, UI_POSI[9] +BATSU_SIZE / 2.0,
			UI_POSI[8] -BATSU_SIZE / 2.0, UI_POSI[9] +BATSU_SIZE / 2.0
			, Batu, true);
	}
	if (!lArm) {
		DrawModiGraph(
			UI_POSI[10] -BATSU_SIZE / 2.0, UI_POSI[11] -BATSU_SIZE / 2.0,
			UI_POSI[10] +BATSU_SIZE / 2.0, UI_POSI[11] -BATSU_SIZE / 2.0,
			UI_POSI[10] +BATSU_SIZE / 2.0, UI_POSI[11] +BATSU_SIZE / 2.0,
			UI_POSI[10] -BATSU_SIZE / 2.0, UI_POSI[11] +BATSU_SIZE / 2.0
			, Batu, true);
	}
	if (!rLeg) {
		DrawModiGraph(
			UI_POSI[12] -BATSU_SIZE / 2.0, UI_POSI[13] -BATSU_SIZE / 2.0,
			UI_POSI[12] +BATSU_SIZE / 2.0, UI_POSI[13] -BATSU_SIZE / 2.0,
			UI_POSI[12] +BATSU_SIZE / 2.0, UI_POSI[13] +BATSU_SIZE / 2.0,
			UI_POSI[12] -BATSU_SIZE / 2.0, UI_POSI[13] +BATSU_SIZE / 2.0
			, Batu, true);
	}
	if (!lLeg) {
		DrawModiGraph(
			UI_POSI[14] -BATSU_SIZE / 2.0, UI_POSI[15] -BATSU_SIZE / 2.0,
			UI_POSI[14] +BATSU_SIZE / 2.0, UI_POSI[15] -BATSU_SIZE / 2.0,
			UI_POSI[14] +BATSU_SIZE / 2.0, UI_POSI[15] +BATSU_SIZE / 2.0,
			UI_POSI[14] -BATSU_SIZE / 2.0, UI_POSI[15] +BATSU_SIZE / 2.0
			, Batu, true);
	}
	if (havekey) {
		DrawModiGraph(
			UI_POSI[16] - KEY_WIDTH / 2.0, UI_POSI[17] - KEY_HEIGHT / 2.0,
			UI_POSI[16] + KEY_WIDTH / 2.0, UI_POSI[17] - KEY_HEIGHT / 2.0,
			UI_POSI[16] + KEY_WIDTH / 2.0, UI_POSI[17] + KEY_HEIGHT / 2.0,
			UI_POSI[16] - KEY_WIDTH / 2.0, UI_POSI[17] + KEY_HEIGHT / 2.0
			, haveKey, true);
	}

	/*for (int i = 0; i < 9; i++) {
		DrawCircle(UI_POSI[2 * i], UI_POSI[2 * i + 1], 20, RED, 1);
	}*/

	//DrawFormatString(0, 20, RED, "Draw UI");
	//if (count < NORMAL_COUNT) {
	//	DrawModiGraph(
	//		UI_MARGIN_WIDTH, UI_MARGIN_HEIGHT,
	//		UI_WIDTH + UI_MARGIN_WIDTH, UI_MARGIN_HEIGHT,
	//		UI_WIDTH + UI_MARGIN_WIDTH, UI_HEIGHT + UI_MARGIN_HEIGHT,
	//		UI_MARGIN_WIDTH, UI_HEIGHT + UI_MARGIN_HEIGHT, UIBack, true);
	
	//DrawFormatStringFToHandle(DISP_WIDTH - 500, 10, BROWN, nishiki, "SCORE : %5d", Score);
	return 0;
}

int Player::SetPimage(int a) {
	Pimage = a;
	return 0;
}
double Player::GetSpeed() {
	return  Speed;
}

int Player::SetSpeed(double a) {
	Speed = a;
	return 0;
}
Circle Player::GetCircle() {
	return player;
}
Dot Player::GetMove() {
	return move;
}
Dot Player::GetDot() {
	return player.GetDot();
}
int Player::keyGet() {
	havekey = true;
	return 0;
}
bool Player::GetKeyflag() {
	return havekey;
}
bool Player::isGameOver() {
	if (!lLeg && !rLeg) return true;
	if (!rEye && !lEye) return true;
	return false;
}
bool Player::isEar() {
	if (!lEar && !rEar) {
		return false;
	}
	else
		return true;
}
bool Player::isArm() {
	if (!lArm && !rArm) {
		return false;
	}
	else
		return true;
}


int pram;
int PlayPWalk() {
	pram = GetRand();
	PlaySoundMem(PWalk[pram%8], DX_PLAYTYPE_BACK);
	//DrawFormatString(0, 40, RED, "Sound!");
	return 0;
}
int yesPSounds() {
	for (int i = 0; i < 8; i++) {
		ChangeVolumeSoundMem(255, PWalk[i]);
	}
	return 0;
}
int noPSounds() {
	for (int i = 0; i < 8; i++) {
		ChangeVolumeSoundMem(0, PWalk[i]);
	}
	return 0;
}
