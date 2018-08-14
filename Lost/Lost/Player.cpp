#include"DxLib.h"
#include"Player.h"
#include"Value.h"
#include"Chore.h"
#include"EnemyMng.h"
#include"Color.h"

int normalImage;
int larmImage;
int maskImage;
int PWalk[8];
Dot center;
Color Wall;
Color Door;
Color Floor1;
Color Floor2;
Color Lowstep;
Color Highstep;

int Player::Initialize() {	//複数プレイヤーならもっと丁寧にやること
	normalImage = LoadGraph("images/player/normal.png");
	larmImage = LoadGraph("images/player/larm.png");
	maskImage = LoadGraph("images/player/mask.png");

	PWalk[0] = LoadSoundMem("sounds/player/1.wav");
	PWalk[1] = LoadSoundMem("sounds/player/2.wav");
	PWalk[2] = LoadSoundMem("sounds/player/3.wav");
	PWalk[3] = LoadSoundMem("sounds/player/4.wav");
	PWalk[4] = LoadSoundMem("sounds/player/5.wav");
	PWalk[5] = LoadSoundMem("sounds/player/6.wav");
	PWalk[6] = LoadSoundMem("sounds/player/7.wav");
	PWalk[7] = LoadSoundMem("sounds/player/8.wav");

	Wall.Initialize(255, 0, 0);
	Door.Initialize(0, 255, 0);
	Floor1.Initialize(0, 0, 255);
	Floor2.Initialize(255, 255, 0);
	Lowstep.Initialize(255, 0, 255);
	Highstep.Initialize(0, 255, 255);
	SetPimage(normalImage);
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
	Speed = P_FULL_SPEED;
	move.Set(0, 0);
	return 0;
}

int Player::Reborn() {
	player.Set(P_REBORN_X, P_REBORN_Y, P_SIZE, 0);
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

	if (Y == 1) {
		if (lArm)
			lArm = false;
		else
			lArm = true;
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
	}

	if (floor == 4) {	//2階にいるとき
		if (!lArm) {
			if (Door.IsHitMoving(player, GetFloor2SoftHandle())) {	//ドアにぶつかれば
				PlayerMoveInColor(&player, GetMove());
				return 0;
			}
		}
		if (Wall.IsHitMoving(player, GetFloor2SoftHandle())) {	//壁にぶつかれば
			PlayerMoveInColor(&player, GetMove());
			return 0;
		}
		if (Highstep.IsHitCircle(player, GetFloor2SoftHandle())) {	//2階の階段にいるとき
			SetFloor(3);
			return 0;
		}
	}
	else if (floor == 3) {
		//if (Wall.IsHitMoving(player, GetFloor2SoftHandle()) || Wall.IsHitMoving(player, GetFloor1SoftHandle())) {	//壁にぶつかれば
		//	PlayerMoveInColor(&player, GetMove());
		//	return 0;
		//}
		if (Floor2.IsHitCircle(player, GetFloor2SoftHandle())) {
			SetFloor(4);
			return 0;
		}
		if (Lowstep.IsHitCircle(player, GetFloor1SoftHandle())) {
			SetFloor(2);
			return 0;
		}
	}
	else if (floor == 2) {
		//if (Wall.IsHitMoving(player, GetFloor2SoftHandle()) || Wall.IsHitMoving(player, GetFloor1SoftHandle())) {	//壁にぶつかれば
		//	PlayerMoveInColor(&player, GetMove());
		//	return 0;
		//}
		if (Floor1.IsHitCircle(player, GetFloor1SoftHandle())) {
			SetFloor(1);
			return 0;
		}
		if (Highstep.IsHitCircle(player, GetFloor2SoftHandle())) {
			SetFloor(3);
			return 0;
		}
	}
	else if (floor == 1) {	//1階にいるとき
		if (!lArm) {
			if (Door.IsHitMoving(player, GetFloor1SoftHandle())) {	//ドアにぶつかれば
				PlayerMoveInColor(&player, GetMove());
				return 0;
			}
		}
		if (Wall.IsHitMoving(player, GetFloor1SoftHandle())) {	//壁にぶつかれば
			PlayerMoveInColor(&player, GetMove());
			return 0;
		}
		if (Lowstep.IsHitCircle(player, GetFloor1SoftHandle())) {	//2階の階段にいるとき
			SetFloor(2);
			return 0;
		}
	}

	player.Move(GetMove());

	return 0;
}

Dot decoi[4];
int Player::Draw() {//ここも大変、特にマスク処理 ←　マスクは画像の上書きで行く，とりあえず全体表示をしっかり

	DrawFormatString(300, 0, RED, "PLAYER DRAW");
	//DrawFormatString(300, 20, RED, "dir:%f", player.GetDir() * 180 / PI);
	//DrawFormatString(300, 20, RED, "floor:%d", GetFloor());
	DrawFormatString(300, 20, RED, "bodyclock:%d", bodyClock);
	//if (!lArm) DrawFormatString(300, 20, RED, "Lost!");

	if (rEye) {

	}
	if (lEye) {

	}
	decoi[0].Setx(DISP_WIDTH / 2.0 - P_SIZE);
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
		decoi[2].Getx(), decoi[2].Gety(), decoi[3].Getx(), decoi[3].Gety(), Pimage, true);

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

	DrawModiGraph(decoi[0].Getx(), decoi[0].Gety(), decoi[1].Getx(), decoi[1].Gety(),
		decoi[2].Getx(), decoi[2].Gety(), decoi[3].Getx(), decoi[3].Gety(), maskImage, true);

	return 0;
}
int Player::UIDraw(int count) {
	DrawFormatString(0, 20, RED, "Draw UI");
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
Circle Player::Getplayer() {
	return player;
}
Dot Player::GetMove() {
	return move;
}

int pram;
int PlayPWalk() {
	pram = GetRand();
	PlaySoundMem(PWalk[pram%8], DX_PLAYTYPE_BACK);
	DrawFormatString(0, 40, RED, "Sound!");
	return 0;
}
