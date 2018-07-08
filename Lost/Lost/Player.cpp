#include"DxLib.h"
#include"Player.h"
#include"Value.h"
#include"Chore.h"
#include "EnemyMng.h"

int normalImage;

int Player::Initialize() {
	normalImage = LoadGraph("images/player/normal.png");
	SetPimage(normalImage);
	return 0;
}

int Player::Set() {
	player.Set(P_REBORN_X, P_REBORN_Y, P_SIZE, 0);
	rEye = true;
	lEye = true;
	rArm = true;
	lArm = true;
	rEar = true;
	lEar = true;
	rLeg = true;
	lLeg = true;
	Speed = P_FULL_SPEED;
	return 0;
}

int Player::Reborn() {
	player.Set(P_REBORN_X, P_REBORN_Y, P_SIZE, 0);
	return 0;
}

int Player::Updata(int Key[], int flag) {
	player.Move(THUMB_X * GetSpeed(), THUMB_Y * GetSpeed());

	if (IsHitColorCtoAll(player,WALL,GetNowFloorHandle())) {//壁ならback
		player.Move(-THUMB_X * GetSpeed(), -THUMB_Y * GetSpeed());
	}
	if (!lArm) {//左手がなければ
		if (IsHitColorCtoAll(player, DOOR, GetNowFloorHandle())) {//ドアならback
			player.Move(-THUMB_X * GetSpeed(), -THUMB_Y * GetSpeed());
		}
	}
	if (IsHitColorDot(player.GetDot(), FLOOR1, GetNowFloorHandle())) {//現在地を仕込む
		SetFloor1();
	}
	if (IsHitColorDot(player.GetDot(), STEP1, GetNowFloorHandle())) {//現在地を仕込む
		SetStep1();
	}
	if (IsHitColorDot(player.GetDot(), STEP2, GetNowFloorHandle())) {//現在地を仕込む
		SetStep2();
	}
	if (IsHitColorDot(player.GetDot(), FLOOR2, GetNowFloorHandle())) {//現在地を仕込む
		SetFloor2();
	}
	
	return 0;
}

Dot decoi[4];
int Player::Draw() {//ここも大変、特にマスク処理

	if (rEye) {

	}
	if (lEye) {

	}
	decoi[0].Setx(player.GetDot().Get_x() - P_SIZE);
	decoi[0].Sety(player.GetDot().Get_y() - P_SIZE);
	decoi[0] = RotateDot(player.GetDir(), decoi[0], player.GetDot());

	decoi[1].Setx(player.GetDot().Get_x() + P_SIZE);
	decoi[1].Sety(player.GetDot().Get_y() - P_SIZE);
	decoi[1] = RotateDot(player.GetDir(), decoi[1], player.GetDot());

	decoi[2].Setx(player.GetDot().Get_x() + P_SIZE);
	decoi[2].Sety(player.GetDot().Get_y() + P_SIZE);
	decoi[2] = RotateDot(player.GetDir(), decoi[2], player.GetDot());

	decoi[3].Setx(player.GetDot().Get_x() - P_SIZE);
	decoi[3].Sety(player.GetDot().Get_y() + P_SIZE);
	decoi[3] = RotateDot(player.GetDir(), decoi[3], player.GetDot());

	/*if (Getplayer().GetRadius() < 0) */
	DrawModiGraph(decoi[0].Get_x(),decoi[0].Get_y(), decoi[1].Get_x(), decoi[1].Get_y(), 
		decoi[2].Get_x(), decoi[2].Get_y(), decoi[3].Get_x(), decoi[3].Get_y(), Pimage, true);
	/*else DrawModiGraph(RotatePoint_x(Get_Dir(), P_x - Get_Size(), P_y - Get_Size(), P_x, P_y), RotatePoint_y(Get_Dir(), P_x - Get_Size(), P_y - Get_Size(), P_x, P_y),
		RotatePoint_x(Get_Dir(), P_x + Get_Size(), P_y - Get_Size(), P_x, P_y), RotatePoint_y(Get_Dir(), P_x + Get_Size(), P_y - Get_Size(), P_x, P_y),
		RotatePoint_x(Get_Dir(), P_x + Get_Size(), P_y + Get_Size(), P_x, P_y), RotatePoint_y(Get_Dir(), P_x + Get_Size(), P_y + Get_Size(), P_x, P_y),
		RotatePoint_x(Get_Dir(), P_x - Get_Size(), P_y + Get_Size(), P_x, P_y), RotatePoint_y(Get_Dir(), P_x - Get_Size(), P_y + Get_Size(), P_x, P_y), P_image, true);*/
	return 0;
}
int Player::UIDraw(int count) {
	DrawFormatString(0, 0, RED, "UI?");
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
