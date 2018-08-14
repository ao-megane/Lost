#include"EnemyMng.h"
#include"Value.h"
#include"Chore.h"
#include"Obj.h"

Dot decoi_e[4];

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
	move.Set(Speed*cos(dir_e), -Speed*sin(dir_e));
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
	ischase = false;
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
	ischase = false;
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

int Son::Set() {
	switch (GetRand() % 1) {
	case 0:
		enemy.Set(2745, 2561, HUSBAND_RANGE, 0);	//具体的な値はマップ依存，csvもあり
		break;
	case 1:
		enemy.Set(0, 0, HUSBAND_RANGE, 0);
		break;
	}
	move.Set(0, 0);
	ischase = true;
	Speed = SON_HALF_SPEED;
	/*decoi_e[0].Set(enemy.Getx() + enemy.GetRadius() + DISP_WIDTH / 2.0 - player.Getx(),
		enemy.Gety() - SON_SERCH_HEIGHT / 2.0 + DISP_HEIGHT / 2.0 - player.Gety());
	decoi_e[1].Set(enemy.Getx() + enemy.GetRadius() + DISP_WIDTH / 2.0 - player.Getx() + SON_SERCH_WIDTH,
		enemy.Gety() + SON_SERCH_HEIGHT / 2.0 + DISP_HEIGHT / 2.0 - player.Gety());
	serch.Set(decoi_e[0], decoi_e[1], enemy.GetDir());*/
	return 0;
}

Dot dest_ene;
int Son::Updata(Circle player) {
	//ここが大変，がんばれ

	if (player&enemy) {
		return 1;
	}

	/*------移動---------*/
	if (ischase) {
		UpdataMove(player.GetDot());
	}
	//else {
	//	//UpdataMove(??);
	//}
	if (!(GetMove().Getx() == 0 && GetMove().Gety() == 0)) { //移動してれば
		enemy.SetDir(CalcDir(move.Getx(),move.Gety()));
	}

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

	enemy.Move(GetMove());

	
	return 0;
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
	ischase = false;
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
		DrawFormatString(300, 20, RED, "move:(%5f,%5f)",son.GetMove().Getx(),son.GetMove().Gety());
		daughter.Draw(player);
		//DrawFormatString(500, 0, RED, "SON_DRAWING");
	}
	else if (floor == 1) {
		husband.Draw(player);
		madam.Draw(player);
	}
	return 0;
}

bool Son::Getischase() {
	return ischase;
}