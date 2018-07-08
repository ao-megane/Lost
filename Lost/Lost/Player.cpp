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


int Player::Updata(int Key[], int flag) {
	player.Move(THUMB_X * GetSpeed(), THUMB_Y * GetSpeed());

	if (IsHitColor(player,WALL,GetNowFloorHandle())) {//壁ならback
		player.Move(-THUMB_X * GetSpeed(), -THUMB_Y * GetSpeed());
	}
	if (!lArm) {//左手がなければ 
		if (IsHitColor(player, DOOR, GetNowFloorHandle())) {//ドアならback
			player.Move(-THUMB_X * GetSpeed(), -THUMB_Y * GetSpeed());
		}
	}
	if (IsHitColor(player, STEP1, GetNowFloorHandle())) {//現在地を仕込む

	}
	
	return 0;
}

int Player::Draw() {//ここも大変、特にマスク処理
	if (rEye) {

	}
	if (lEye) {

	}

}

int Player::SetPimage(char a[]) {
	Pimage = LoadGraph(a);
}
double Player::GetSpeed() {
	return  Speed;
}
