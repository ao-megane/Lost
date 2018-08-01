#include"DxLib.h"
#include"Player.h"
#include"Value.h"
#include"Chore.h"
#include"EnemyMng.h"
#include"Color.h"

int normalImage;
Color Wall;


int Player::Initialize() {
	normalImage = LoadGraph("images/player/normal.png");
	Wall.Initialize(0, 0, 0);
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

	DrawFormatString(0, 60, RED, "%d", WALL);
	DrawFormatString(0, 80, RED, "%d", GetPixelPalCodeSoftImage(GetNowFloorSoftHandle(), player.GetDot().Getx(), player.GetDot().Gety()));

	if (!(THUMB_X == 0 && THUMB_Y == 0))	//問題なければ進む
		player.Move(THUMB_X * GetSpeed() / 100.0, THUMB_Y * GetSpeed() / 100.0);

	if (Wall.IsHitPlayer(player,GetNowFloorSoftHandle())) {//壁ならback
		DrawFormatString(0, 100, RED, "壁！！！！！！");
		player.Back(THUMB_X * GetSpeed() / 100.0, THUMB_Y * GetSpeed() / 100.0);
		return 0;
	}
	//if (!lArm) {//左手がなければ
	//	if (IsHitColorCtoAll(player, DOOR, GetNowFloorSoftHandle())) {//ドアならback
	//		player.Move(-THUMB_X * GetSpeed(), -THUMB_Y * GetSpeed());
	//	}
	//}

	//if (IsHitColorDot(player.GetDot(), FLOOR1, GetNowFloorSoftHandle())) {//現在地を仕込む
	//	//SetFloor1();
	//}
	//if (IsHitColorDot(player.GetDot(), STEP1, GetNowFloorSoftHandle())) {//現在地を仕込む
	//	SetStep1();
	//}
	//if (IsHitColorDot(player.GetDot(), STEP2, GetNowFloorSoftHandle())) {//現在地を仕込む
	//	SetStep2();
	//}
	//if (IsHitColorDot(player.GetDot(), FLOOR2, GetNowFloorSoftHandle())) {//現在地を仕込む
	//	SetFloor2();
	//}
	

	
	return 0;
}

Dot decoi[4];
int Player::Draw() {//ここも大変、特にマスク処理 ←　マスクは画像の上書きで行く，とりあえず全体表示をしっかり

	if (rEye) {

	}
	if (lEye) {

	}
	decoi[0].Setx(player.GetDot().Getx() - P_SIZE);
	decoi[0].Sety(player.GetDot().Gety() - P_SIZE);
	decoi[0] = RotateDot(player.GetDir(), decoi[0], player.GetDot());

	decoi[1].Setx(player.GetDot().Getx() + P_SIZE);
	decoi[1].Sety(player.GetDot().Gety() - P_SIZE);
	decoi[1] = RotateDot(player.GetDir(), decoi[1], player.GetDot());

	decoi[2].Setx(player.GetDot().Getx() + P_SIZE);
	decoi[2].Sety(player.GetDot().Gety() + P_SIZE);
	decoi[2] = RotateDot(player.GetDir(), decoi[2], player.GetDot());

	decoi[3].Setx(player.GetDot().Getx() - P_SIZE);
	decoi[3].Sety(player.GetDot().Gety() + P_SIZE);
	decoi[3] = RotateDot(player.GetDir(), decoi[3], player.GetDot());

	/*if (Getplayer().GetRadius() < 0) */
	DrawModiGraph(decoi[0].Getx(),decoi[0].Gety(), decoi[1].Getx(), decoi[1].Gety(), 
		decoi[2].Getx(), decoi[2].Gety(), decoi[3].Getx(), decoi[3].Gety(), Pimage, true);
	/*else DrawModiGraph(RotatePoint_x(Get_Dir(), P_x - Get_Size(), P_y - Get_Size(), P_x, P_y), RotatePoint_y(Get_Dir(), P_x - Get_Size(), P_y - Get_Size(), P_x, P_y),
		RotatePoint_x(Get_Dir(), P_x + Get_Size(), P_y - Get_Size(), P_x, P_y), RotatePoint_y(Get_Dir(), P_x + Get_Size(), P_y - Get_Size(), P_x, P_y),
		RotatePoint_x(Get_Dir(), P_x + Get_Size(), P_y + Get_Size(), P_x, P_y), RotatePoint_y(Get_Dir(), P_x + Get_Size(), P_y + Get_Size(), P_x, P_y),
		RotatePoint_x(Get_Dir(), P_x - Get_Size(), P_y + Get_Size(), P_x, P_y), RotatePoint_y(Get_Dir(), P_x - Get_Size(), P_y + Get_Size(), P_x, P_y), P_image, true);*/
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
