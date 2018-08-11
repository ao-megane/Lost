#include"DxLib.h"
#include"Player.h"
#include"Value.h"
#include"Chore.h"
#include"EnemyMng.h"
#include"Color.h"

int normalImage;
Dot center;
Color Wall;
Color Door;
Color Floor1;
Color Floor2;
Color Lowstep;
Color Highstep;

int Player::Initialize() {
	normalImage = LoadGraph("images/player/normal.png");
	Wall.Initialize(255, 0, 0);
	Door.Initialize(0, 255, 0);
	Floor1.Initialize(0, 0, 255);
	Floor2.Initialize(255, 255, 0);
	Lowstep.Initialize(255, 0, 255);
	Highstep.Initialize(0, 255, 255);
	SetPimage(normalImage);
	move.Set(0, 0);
	SetFloor(1);
	center.Set(DISP_WIDTH / 2.0, DISP_HEIGHT / 2.0);
	return 0;
}

int Player::Set() {
	player.Set(P_REBORN_X, P_REBORN_Y, P_SIZE, 0);
	SetFloor(1);
	rEye = true;
	lEye = true;
	rArm = true;
	lArm = false;
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

	DrawFormatString(0, 60, RED, "%d", WALL);
	//DrawFormatString(0, 80, RED, "%d", GetPixelPalCodeSoftImage(GetNowFloorSoftHandle(), player.GetDot().Getx(), player.GetDot().Gety()));

	UpdataMove(THUMB_X * GetSpeed() / 100.0, THUMB_Y * GetSpeed() / 100.0);

	if (floor == 4) {
		if (!Wall.IsHitMoving(player, GetFloor2SoftHandle(), GetMove())) {//壁判定(移動含む) 当たれば他の判定はしない
			PlayerMoveInColor(&player, GetMove());
			return 0;
		}
		else if (!lArm) {//左手がなければ
			if(!Door.IsHitMoving(player, GetFloor2SoftHandle(), GetMove()))
				PlayerMoveInColor(&player, GetMove());
			return 0;
		}
	}
	else if (floor == 1) {
		if (!Wall.IsHitMoving(player, GetFloor1SoftHandle(), GetMove())) {//壁判定(移動含む) 当たれば他の判定はしない
			PlayerMoveInColor(&player, GetMove());
			return 0;
		}
		else if (!lArm) {//左手がなければ
			if(!Door.IsHitMoving(player, GetFloor1SoftHandle(), GetMove()))
				PlayerMoveInColor(&player, GetMove());
			return 0;
		}
	}

	//if (Floor1.IsHitCircle(player, GetFloor1SoftHandle())) {
	//	SetFloor(1);
	//}
	//if (Lowstep.IsHitCircle(player, GetLowstepSoftHandle())) {
	//	SetFloor(2);
	//}
	//if (Highstep.IsHitCircle(player, GetHighstepSoftHandle())) {
	//	SetFloor(3);
	//}
	//if (Floor2.IsHitCircle(player, GetFloor2SoftHandle())) {
	//	SetFloor(4);
	//}

	return 0;
}

Dot decoi[4];
int Player::Draw() {//ここも大変、特にマスク処理 ←　マスクは画像の上書きで行く，とりあえず全体表示をしっかり

	DrawFormatString(300, 0, RED, "PLAYER DRAW");

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

	/*if (Getplayer().GetRadius() < 0) */
	DrawModiGraph(decoi[0].Getx(),decoi[0].Gety(), decoi[1].Getx(), decoi[1].Gety(), 
		decoi[2].Getx(), decoi[2].Gety(), decoi[3].Getx(), decoi[3].Gety(), Pimage, true);

	/*DrawModiGraph(
		DISP_WIDTH / 2.0 - player.GetRadius(), DISP_HEIGHT / 2.0 - player.GetRadius(),
		DISP_WIDTH / 2.0 + player.GetRadius(), DISP_HEIGHT / 2.0 - player.GetRadius(),
		DISP_WIDTH / 2.0 + player.GetRadius(), DISP_HEIGHT / 2.0 + player.GetRadius(),
		DISP_WIDTH / 2.0 - player.GetRadius(), DISP_HEIGHT / 2.0 + player.GetRadius(),
		Pimage, true);*/
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
Circle Player::Getplayer() {
	return player;
}
Dot Player::GetMove() {
	return move;
}