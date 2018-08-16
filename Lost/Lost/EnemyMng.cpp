#include"EnemyMng.h"
#include"Value.h"
#include"Chore.h"
#include"Obj.h"

Dot decoi_e[4];
Dot DEST1[27];
Dot DEST2[20];

int Enemy::Draw(Dot player){
	DrawFormatString(300, 0, RED, "ENEMY DRAW");

	decoi_e[0].Setx(enemy.GetDot().Getx() - enemy.GetRadius());
	decoi_e[0].Sety(enemy.GetDot().Gety() - enemy.GetRadius());
	decoi_e[0] = RotateDot(enemy.GetDir(), decoi_e[0], enemy.GetDot());

	decoi_e[1].Setx(enemy.GetDot().Getx() + enemy.GetRadius());
	decoi_e[1].Sety(enemy.GetDot().Gety() - enemy.GetRadius());
	decoi_e[1] = RotateDot(enemy.GetDir(), decoi_e[1], enemy.GetDot());

	decoi_e[2].Setx(enemy.GetDot().Getx() + enemy.GetRadius());
	decoi_e[2].Sety(enemy.GetDot().Gety() + enemy.GetRadius());
	decoi_e[2] = RotateDot(enemy.GetDir(), decoi_e[2], enemy.GetDot());

	decoi_e[3].Setx(enemy.GetDot().Getx() - enemy.GetRadius());
	decoi_e[3].Sety(enemy.GetDot().Gety() + enemy.GetRadius());
	decoi_e[3] = RotateDot(enemy.GetDir(), decoi_e[3], enemy.GetDot());

	DrawModiGraph(
		decoi_e[0].Getx() + DISP_WIDTH / 2.0 - player.Getx(), decoi_e[0].Gety() + DISP_HEIGHT / 2.0 - player.Gety(),
		decoi_e[1].Getx() + DISP_WIDTH / 2.0 - player.Getx(), decoi_e[1].Gety() + DISP_HEIGHT / 2.0 - player.Gety(),
		decoi_e[2].Getx() + DISP_WIDTH / 2.0 - player.Getx(), decoi_e[2].Gety() + DISP_HEIGHT / 2.0 - player.Gety(),
		decoi_e[3].Getx() + DISP_WIDTH / 2.0 - player.Getx(), decoi_e[3].Gety() + DISP_HEIGHT / 2.0 - player.Gety(),
		Eimage, true);
	//DrawCircle(enemy.Getx() + DISP_WIDTH / 2.0 - player.Getx(), enemy.Gety() + DISP_HEIGHT / 2.0 - player.Gety(), enemy.GetRadius(), BLUE, 1, 0);

	serch.Draw(BLUE,enemy.GetRadius());

	return 0;
}
double dir_e;
int Enemy::UpdataMove(Dot a) {
	dir_e = CalcDir(enemy.GetDot(), a);
	//dir_e = CalcDir(enemy.GetDot().Getx() - a.Getx(), enemy.GetDot().Gety() - a.Gety());
	move.Set(Speed*cos(dir_e), -Speed*sin(dir_e));
	//printfDx("dir:%f,enedot(%f,%f),nextdot(%f,%f)\n", dir_e * 180.0 / PI ,enemy.GetDot().Getx(),enemy.GetDot().Gety(),a.Getx(),a.Gety());
	return 0;
}
Dot Enemy::GetMove() {
	return move;
}

int Husband::Initialize() {
	image[0] = LoadGraph("images/enemy/husband/1.png");
	image[1] = LoadGraph("images/enemy/husband/2.png");
	image[2] = LoadGraph("images/enemy/husband/3.png");
	image[3] = LoadGraph("images/enemy/husband/4.png");
	image[4] = LoadGraph("images/enemy/husband/5.png");
	image[5] = LoadGraph("images/enemy/husband/6.png");
	image[6] = LoadGraph("images/enemy/husband/7.png");
	image[7] = LoadGraph("images/enemy/husband/8.png");
	Eimage = image[0];
	move.Set(0, 0);
	return 0;
}

int Husband::Set() {
	switch (GetRand() % 1) {
	case 0:
		enemy.Set(0, 0, HUSBAND_RANGE, 0);	//具体的な値はマップ依存，csvもあり
		break;
	case 1:
		enemy.Set(0, 0, HUSBAND_RANGE, 0);
		break;
	}
	move.Set(0, 0);
	stateflag = 0;
	Speed = HUSBAND_HALF_SPEED;
	return 0;
}

int Husband::Updata(Circle player) {
	/* ここが大変，がんばれ
	
	*/
	if (player&enemy) 
		return 1;
	return 0;
}

int Madam::Initialize() {
	image[0] = LoadGraph("images/enemy/madam/1.png");
	image[1] = LoadGraph("images/enemy/madam/2.png");
	image[2] = LoadGraph("images/enemy/madam/3.png");
	image[3] = LoadGraph("images/enemy/madam/4.png");
	image[4] = LoadGraph("images/enemy/madam/5.png");
	image[5] = LoadGraph("images/enemy/madam/6.png");
	image[6] = LoadGraph("images/enemy/madam/7.png");
	image[7] = LoadGraph("images/enemy/madam/8.png");
	Eimage = image[0];
	move.Set(0, 0);
	return 0;
}

int Madam::Set() {
	switch (GetRand() % 6) {
	case 0:
		enemy.Set(0, 0, HUSBAND_RANGE, 0);	//具体的な値はマップ依存，csvもあり
		break;
	case 1:
		enemy.Set(0, 0, HUSBAND_RANGE, 0);
		break;
	}
	move.Set(0, 0);
	stateflag = 0;
	Speed = MADAM_HALF_SPEED;
	return 0;
}

int Madam::Updata(Circle player) {
	/* ここが大変，がんばれ

	*/
	if (player&enemy)
		return 1;
	return 0;
}

int Son::Initialize() {
	image[0] = LoadGraph("images/enemies/son/1.png");
	image[1] = LoadGraph("images/enemies/son/2.png");
	image[2] = LoadGraph("images/enemies/son/3.png");
	image[3] = LoadGraph("images/enemies/son/4.png");
	image[4] = LoadGraph("images/enemies/son/5.png");
	image[5] = LoadGraph("images/enemies/son/6.png");
	image[6] = LoadGraph("images/enemies/son/7.png");
	image[7] = LoadGraph("images/enemies/son/8.png");
	Eimage = image[0];
	move.Set(0, 0);
	return 0;
}

int kakashi_e;
int Son::Set() {
	kakashi_e = GetRand() % 20;
	enemy.Set(ENEPOSI_2[2 * kakashi_e], ENEPOSI_2[2 * kakashi_e + 1], SON_RANGE, 0);
	nextNum = kakashi_e;
	printfDx("%d", nextNum);
	move.Set(0, 0);
	stateflag = 0;
	Speed = SON_HALF_SPEED;
	return 0;
}

Dot dest_ene;
int Son::Updata(Circle player) {
	//ここが大変，がんばれ
	if (stateflag == 0) {	//塁上
		kakashi_e = GetRand() % 100;
		switch (nextNum + 1)	//ここだけ1base
		{
		case 1:
			if (kakashi_e < 30) {
				dest_ene = DEST2[6 - 1];
				nextNum = 6 - 1;
			}
			else if (kakashi_e < 30 + 35) {
				dest_ene = DEST2[3 - 1];
				nextNum = 3 - 1;
			}
			else if (kakashi_e < 100) {
				dest_ene = DEST2[2 - 1];
				nextNum = 2 - 1;
			}
			break;
		case 2:
			if (kakashi_e < 49) {
				dest_ene = DEST2[1 - 1];
				nextNum = 1 - 1;
			}
			else if (kakashi_e < 100) {
				dest_ene = DEST2[19 - 1];
				nextNum = 19 - 1;
			}
			break;
		case 3:
			if (kakashi_e < 33){
				dest_ene = DEST2[1 - 1];
				nextNum = 1 - 1;
			}
			else if (kakashi_e < 33 + 33){
				dest_ene = DEST2[4 - 1];
				nextNum = 4 - 1;
			}
			else if (kakashi_e < 100){
				dest_ene = DEST2[5 - 1];
				nextNum = 5 - 1;
			}
			break;
		case 4:
			if (kakashi_e < 30){
				dest_ene = DEST2[20 - 1];
				nextNum = 20 - 1;
			}
			else if (kakashi_e < 100){
				dest_ene = DEST2[3 - 1];
				nextNum = 3 - 1;
			}
			break;
		case 5:
			if (kakashi_e < 50){
				dest_ene = DEST2[3 - 1];
				nextNum = 3 - 1;
			}
			else if (kakashi_e < 100){
				dest_ene = DEST2[8 - 1];
				nextNum = 8 - 1;
			}
			break;
		case 6:
			if (kakashi_e < 30){
				dest_ene = DEST2[7 - 1];
				nextNum = 7 - 1;
			}
			else if (kakashi_e < 100){
				dest_ene = DEST2[1 - 1];
				nextNum = 1 - 1;
			}
			break;
		case 7:
			if (kakashi_e < 100){
				dest_ene = DEST2[6 - 1];
				nextNum = 6 - 1;
			}
			break;
		case 8:
			if (kakashi_e < 30){
				dest_ene = DEST2[9 - 1];
				nextNum = 9 - 1;
			}
			else if (kakashi_e < 30 + 35){
				dest_ene = DEST2[5 - 1];
				nextNum = 5 - 1;
			}
			else if (kakashi_e < 100){
				dest_ene = DEST2[12 - 1];
				nextNum = 12 - 1;
			}
			break;
		case 9:
			if (kakashi_e < 30){
				dest_ene = DEST2[10 - 1];
				nextNum = 10 - 1;
			}
			else if (kakashi_e < 100){
				dest_ene = DEST2[8 - 1];
				nextNum = 8 - 1;
			}
			break;
		case 10:
			if (kakashi_e < 30){
				dest_ene = DEST2[11 - 1];
				nextNum = 11 - 1;
			}
			else if (kakashi_e < 100){
				dest_ene = DEST2[9 - 1];
				nextNum = 9 - 1;
			}
			break;
		case 11:
			if (kakashi_e < 100){
				dest_ene = DEST2[10 - 1];
				nextNum = 10 - 1;
			}
			break;
		case 12:
			if (kakashi_e < 33){
				dest_ene = DEST2[8 - 1];
				nextNum = 8 - 1;
			}
			else if (kakashi_e < 33 + 33){
				dest_ene = DEST2[16 - 1];
				nextNum = 16 - 1;
			}
			else if (kakashi_e < 100){
				dest_ene = DEST2[13 - 1];
				nextNum = 13 - 1;
			}
			break;
		case 13:
			if (kakashi_e < 30){
				dest_ene = DEST2[14 - 1];
				nextNum = 14 - 1;
			}
			else if (kakashi_e < 30 + 30){
				dest_ene = DEST2[15 - 1];
				nextNum = 15 - 1;
			}
			else if (kakashi_e < 100){
				dest_ene = DEST2[12 - 1];
				nextNum = 12 - 1;
			}
			break;
		case 14:
			if (kakashi_e < 100){
				dest_ene = DEST2[13 - 1];
				nextNum = 13 - 1;
			}
			break;
		case 15:
			if (kakashi_e < 100){
				dest_ene = DEST2[13 - 1];
				nextNum = 13 - 1;
			}
			break;
		case 16:
			if (kakashi_e < 50){
				dest_ene = DEST2[12 - 1];
				nextNum = 12 - 1;
			}
			else if (kakashi_e < 100){
				dest_ene = DEST2[17 - 1];
				nextNum = 17 - 1;
			}
			break;
		case 17:
			if (kakashi_e < 30){
				dest_ene = DEST2[18 - 1];
				nextNum = 18 - 1;
			}
			else if (kakashi_e < 30 + 35){
				dest_ene = DEST2[16 - 1];
				nextNum = 16 - 1;
			}
			else if (kakashi_e < 100){
				dest_ene = DEST2[19 - 1];
				nextNum = 19 - 1;
			}
			break;
		case 18:
			if (kakashi_e < 100){
				dest_ene = DEST2[18 - 1];
				nextNum = 18 - 1;
			}
			break;
		case 19:
			if (kakashi_e < 50){
				dest_ene = DEST2[17 - 1];
				nextNum = 17 - 1;
			}
			else if (kakashi_e < 100){
				dest_ene = DEST2[2 - 1];
				nextNum = 2 - 1;
			}
			break;
		case 20:
			if (kakashi_e < 100){
				dest_ene = DEST2[4 - 1];
				nextNum = 4 - 1;
			}
			break;
		default:
			break;
		}
		UpdataMove(dest_ene);
		dest = dest_ene;
		stateflag = 1;
	}
	else if (stateflag == 1) {//走塁,暇
		Speed = SON_HALF_SPEED;
		//enemy.MoveandTurn(dest);
		if (CalcDistance(enemy.GetDot(), DEST2[nextNum]) < 100) {
			printfDx("到着！！！！！！！！！！！！！\n");
			stateflag = 0;
		}
	}
	else if (stateflag == 2) {//プレイヤーを目視
		Speed = SON_FULL_SPEED;
		//if(遮蔽がなければ)
		UpdataMove(player.GetDot());
		//if(遮蔽があれば)
		//stateflag = 3
	}
	else if (stateflag == 3) {//プレイヤー探す
		Speed = SON_FULL_SPEED;
		//ここ大変，近い点を探して行って，そこから角度込みで近い点をdestにする
		//dest = 
	}

	/*if (player&enemy) {
		return 1;
	}*/

	/*------移動---------*/
	//if (!(GetMove().Getx() == 0 && GetMove().Gety() == 0)) { //移動してれば
	//	enemy.SetDir(CalcDir(move.Getx(),move.Gety()));
	//}

	/*------索敵更新-------*/
	decoi_e[0].Set(
		enemy.Getx() + enemy.GetRadius() + DISP_WIDTH / 2.0 - player.Getx(),
		enemy.Gety() - SON_SERCH_HEIGHT / 2.0 + DISP_HEIGHT / 2.0 - player.Gety());
	decoi_e[1].Set(
		enemy.Getx() + enemy.GetRadius() + DISP_WIDTH / 2.0 - player.Getx() + SON_SERCH_WIDTH,
		enemy.Gety() + SON_SERCH_HEIGHT / 2.0 + DISP_HEIGHT / 2.0 - player.Gety());
	serch.Set(decoi_e[0], decoi_e[1], enemy.GetDir());

	/*-------壁ら-------*/
	if (GetDoor().IsHitMoving(enemy, GetFloor2SoftHandle())) {	//ドアにぶつかれば
		PlayerMoveInColor(&enemy, GetMove());
		return 0;
	}
	if (GetWall().IsHitMoving(enemy, GetFloor2SoftHandle())) {	//壁にぶつかれば
		PlayerMoveInColor(&enemy, GetMove());
		return 0;
	}
	if (GetHighstep().IsHitCircle(enemy, GetFloor2SoftHandle())) {	//2階の階段にいるとき
		PlayerMoveInColor(&enemy, GetMove());
		return 0;
	}
	
	/*if(serch&player)
		ischase = true;*/
	//if(見失う処理)
	//	ischase = false;

	enemy.MoveandTurn(GetMove());
	
	return 0;
}

Dot Son::GetDest(){
	return dest;
}
int Son::GetState() {
	return stateflag;
}
int Son::GetNextNum() {
	return nextNum;
}


int Daughter::Initialize() {
	image[0] = LoadGraph("images/enemy/daughter/1.png");
	image[1] = LoadGraph("images/enemy/daughter/2.png");
	image[2] = LoadGraph("images/enemy/daughter/3.png");
	image[3] = LoadGraph("images/enemy/daughter/4.png");
	image[4] = LoadGraph("images/enemy/daughter/5.png");
	image[5] = LoadGraph("images/enemy/daughter/6.png");
	image[6] = LoadGraph("images/enemy/daughter/7.png");
	image[7] = LoadGraph("images/enemy/daughter/8.png");
	Eimage = image[0];
	move.Set(0, 0);
	return 0;
}

int Daughter::Set() {
	switch (GetRand() % 6) {
	case 0:
		enemy.Set(0, 0, HUSBAND_RANGE, 0);	//具体的な値はマップ依存，csvもあり
		break;
	case 1:
		enemy.Set(0, 0, HUSBAND_RANGE, 0);
		break;
	}
	move.Set(0, 0);
	stateflag = 0;
	Speed = DAUGHTER_HALF_SPEED;
	return 0;
}

int Daughter::Updata(Circle player) {
	/* ここが大変，がんばれ

	*/
	if (player&enemy)
		return 1;
	return 0;
}

Husband husband;
Madam madam;
Son son;
Daughter daughter;
int EnemyMngInitialize() {
	husband.Initialize();
	madam.Initialize();
	son.Initialize();
	daughter.Initialize();

	return 0;
}

int EnemyMngSet() {
	husband.Set();
	madam.Set();
	son.Set();
	daughter.Set();
	for (int i = 0; i < 27; i++) {
		DEST1[i].Set(ENEPOSI_1[2 * i], ENEPOSI_1[2 * i + 1]);
	}
	for (int i = 0; i < 20; i++) {
		DEST2[i].Set(ENEPOSI_2[2 * i], ENEPOSI_2[2 * i + 1]);
	}
	return 0;
}

int EnemyMngUpdata(Circle player,int floor) {
	if (floor == 4) {
		if (son.Updata(player))
			return 1;
		if (daughter.Updata(player))
			return 2;
	}
	else if (floor == 1) {
		if (husband.Updata(player))
			return 3;
		if (madam.Updata(player))
			return 4;
	}
	return 0;
}

int EnemyMngDraw(Dot player,int floor) {
	if (floor == 4) {
		son.Draw(player);
		DrawFormatString(300, 20, RED, "dest:(%5f,%5f)",son.GetDest().Getx(),son.GetDest().Gety());
		DrawFormatString(300, 40, RED, "move:(%5f,%5f)", son.GetMove().Getx(), son.GetMove().Gety());
		DrawFormatString(300, 60, RED, "stateflag:%d", son.GetState());
		DrawFormatString(300, 80, RED, "nextNum:%d", son.GetNextNum());
		for (int i = 0; i < 20; i++) {
			DrawCircle(DEST2[i].Getx() + DISP_WIDTH / 2.0 - player.Getx(), DEST2[i].Gety() + DISP_HEIGHT / 2.0 - player.Gety(), 5, BLUE, 1);
		}
		//daughter.Draw(player);
		//DrawFormatString(500, 0, RED, "SON_DRAWING");
	}
	else if (floor == 1) {
		husband.Draw(player);
		madam.Draw(player);
		for (int i = 0; i < 27; i++) {
			DrawCircle(DEST1[i].Getx() + DISP_WIDTH / 2.0 - player.Getx(), DEST1[i].Gety() + DISP_HEIGHT / 2.0 - player.Gety(), 30, RED, 1);
		}
	}
	return 0;
}

