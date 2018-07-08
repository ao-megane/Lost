#include"DxLib.h"
#include"Player.h"
#include"Value.h"
#include"Chore.h"
#include "EnemyMng.h"

Player::Player(){
	SetPimage("images/player/player.png");
}

int Player::Initialize() {
	player.Set(P_REBORN_X,P_REBORN_Y,P_SIZE,0);
	rEye = true;
	lEye = true;
	rArm = true;
	lArm = true;
	rEar = true;
	lEar = true;
	rLeg = true;
	lLeg = true;
	Speed = P_FULL_SPEED;
}
int Player::Reborn() {
	player.Set(P_REBORN_X, P_REBORN_Y, P_SIZE, 0);
}


int Player::Updata(int Key[], int flag) {
	player.Move(THUMB_X * GetSpeed(), THUMB_Y * GetSpeed());

	if (IsHitColorCtoAll(player,WALL,GetNowFloorHandle())) {//�ǂȂ�back
		player.Move(-THUMB_X * GetSpeed(), -THUMB_Y * GetSpeed());
	}
	if (!lArm) {//���肪�Ȃ���� 
		if (IsHitColorCtoAll(player, DOOR, GetNowFloorHandle())) {//�h�A�Ȃ�back
			player.Move(-THUMB_X * GetSpeed(), -THUMB_Y * GetSpeed());
		}
	}
	if (IsHitColorDot(player.GetDot(), FLOOR1, GetNowFloorHandle())) {//���ݒn���d����
		SetFloor1();
	}
	if (IsHitColorDot(player.GetDot(), STEP1, GetNowFloorHandle())) {//���ݒn���d����
		SetStep1();
	}
	if (IsHitColorDot(player.GetDot(), STEP2, GetNowFloorHandle())) {//���ݒn���d����
		SetStep2();
	}
	if (IsHitColorDot(player.GetDot(), FLOOR2, GetNowFloorHandle())) {//���ݒn���d����
		SetFloor2();
	}
	
	return 0;
}

int Player::Draw() {//��������ρA���Ƀ}�X�N����
	if (rEye) {

	}
	if (lEye) {

	}

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
}

int Player::SetPimage(char a[]) {
	Pimage = LoadGraph(a);
}
double Player::GetSpeed() {
	return  Speed;
}
