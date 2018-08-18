#include"Dxlib.h"
#include"Obj.h"
#include"Color.h"
#include"Value.h"
#include"Chore.h"
#include<math.h>

int Color::Initialize(int a,int ba,int c) {
	r = a;
	g = ba;
	b = c;
	return 0;
}
int Color::GetColorOri() {
	return GetColor(r, g, b);
}
int colordecoi[3];	//r,g,b
bool isHitflag;
double thita1;
double thita2;
Dot touchDot;
Dot resultDot;

bool Color::IsHitMoving(Circle x, int Handle) {
	isHitflag = false;
	/*if(moveDot.Getx() != 0 && moveDot.Gety() != 0)
		thita1 = CalcDir(moveDot);*/
	if (Handle == 0)
		return false;

	for (double i = x.GetRadius(); i > 0; i--) {//��Ԃ��܂������Ă�
		double j = +sqrt(x.GetRadius()*x.GetRadius() - i * i);
		resultDot.Set(i, j);
		resultDot = RotateDot(x.GetDir(), resultDot) + x.GetDot();
		GetPixelSoftImage(Handle, resultDot.Getx(), resultDot.Gety(), &colordecoi[0], &colordecoi[1], &colordecoi[2], 0);
		if (r == colordecoi[0] && g == colordecoi[1] && b == colordecoi[2]) {	//�Ԃ����
			touchDot = resultDot;
			//DrawCircle(touchDot.Getx(), touchDot.Gety(), 20, RED, 1);
			isHitflag = true;
			break;
		}

		j *= -1;
		resultDot.Set(i, j);
		resultDot = RotateDot(x.GetDir(), resultDot) + x.GetDot();
		GetPixelSoftImage(Handle, resultDot.Getx(), resultDot.Gety(), &colordecoi[0], &colordecoi[1], &colordecoi[2], 0);
		if (r == colordecoi[0] && g == colordecoi[1] && b == colordecoi[2]) {	//�Ԃ����
			touchDot = resultDot;
			//DrawCircle(touchDot.Getx(), touchDot.Gety(), 20, RED, 1);
			isHitflag = true;
			break;
		}
	}

	if (isHitflag) return true;
	else return false;

	/*if(!isHitflag)	//���܂������Ă�
	for (double i = x->Getx() - x->GetRadius()- JUDGE_MARGIN * P_FULL_SPEED; i < x->Getx() + x->GetRadius() + JUDGE_MARGIN*P_FULL_SPEED; i++) {
		for (double j = x->Gety() - x->GetRadius() - JUDGE_MARGIN * P_FULL_SPEED; j < x->Gety() + x->GetRadius() + JUDGE_MARGIN * P_FULL_SPEED; j++) {
			if (((i - x->Getx())*(i - x->Getx()) + (j - x->Gety())*(j - x->Gety())) <= (x->GetRadius() + JUDGE_MARGIN * P_FULL_SPEED)*(x->GetRadius() + JUDGE_MARGIN*P_FULL_SPEED) &&
				((i - x->Getx())*(i - x->Getx()) + (j - x->Gety())*(j - x->Gety())) >= (x->GetRadius())*(x->GetRadius())) {
				GetPixelSoftImage(Handle, i, j, &colordecoi[0], &colordecoi[1], &colordecoi[2], 0);
				DrawPixel(i, j, BLUE);
				if (r == colordecoi[0] && g == colordecoi[1] && b == colordecoi[2]) {
					touchDot.Set(i, j);
					DrawCircle(i, j, 20, RED, 1);
					isHitflag = true;
					break;
				}
			}
		}
		if (isHitflag) break;
	}*/
}

int PlayerMoveInColor(Circle* x,Dot moveDot) {	//�Ԃ������Ƃ��p�̈ړ��֐�
	//circle�̒��S�Ɠ��������_(i,j)�Ń��Ƃ���sin����
	thita1 = CalcDir(x->GetDot(), touchDot);
	if (RotateDot(-thita1, moveDot).Getx() > 0) {	//�ǂɌ������Ă����
		resultDot.Set(0, RotateDot(-thita1, moveDot).Gety());

		resultDot = RotateDot(thita1, resultDot);

		x->Move(resultDot);
	}
	else {
		x->Move(moveDot);
	}
	return 0;
}

bool Color::IsHitCircle(Circle x,int Handle) {
	if (Handle == 0)
		return false;
	for (double i = x.Getx() - x.GetRadius(); i < x.Getx() + x.GetRadius(); i++) {
		for (double j = x.Gety() - x.GetRadius(); j < x.Gety() + x.GetRadius(); j++) {
			if (((i - x.Getx())*(i - x.Getx()) + (j - x.Gety())*(j - x.Gety())) <= x.GetRadius()*x.GetRadius()) {
				GetPixelSoftImage(Handle, x.Getx(), x.Gety(), &colordecoi[0], &colordecoi[1], &colordecoi[2], 0);
				if (r == colordecoi[0] && g == colordecoi[1] && b == colordecoi[2])
					return true;
			}
		}
	}
	return false;
}
bool Color::IsHitDot(Dot x,int Handle) {
	GetPixelSoftImage(Handle, x.Getx(), x.Gety(), &colordecoi[0], &colordecoi[1], &colordecoi[2], 0);
	if (r == colordecoi[0] && g == colordecoi[1] && b == colordecoi[2])
		return true;
	else
		return false;
}
bool Color::IsHitDottoDot(Dot a1, Dot a2, int Handle) {
	if (Handle == 0) {
		printfDx("����͂Ȃ�");
		return false;
	}
	if (a1.Getx() > a2.Getx()) {
		Dot decoi;
		decoi = a1;
		a1 = a2;
		a2 = decoi;
	}
	for (double i = 0; i < a2.Getx() - a1.Getx(); i++) {
		GetPixelSoftImage(Handle, i + a1.Getx(), (a2.Gety() - a1.Gety()) / (a2.Getx() - a1.Getx()) * i + a1.Gety(), &colordecoi[0], &colordecoi[1], &colordecoi[2], 0);
		if (r == colordecoi[0] && g == colordecoi[1] && b == colordecoi[2])
			return true;
	}
	return false;
}

Color Wall;
Color Door;
Color Floor1;
Color Floor2;
Color Lowstep;
Color Highstep;
Color Rock;

int ColorMngInitialize() {
	Wall.Initialize(255, 0, 0);
	Door.Initialize(0, 255, 0);
	Floor1.Initialize(0, 0, 255);
	Floor2.Initialize(255, 255, 0);
	Lowstep.Initialize(255, 0, 255);
	Highstep.Initialize(0, 255, 255);
	Rock.Initialize(0, 0, 0);
	return 0;
}

Color GetWall() {
	return Wall;
}
Color GetDoor() {
	return Door;
}
Color GetFloor1() {
	return Floor1;
}
Color GetFloor2() {
	return Floor2;
}
Color GetLowstep() {
	return Lowstep;
}
Color GetHighstep() {
	return Highstep;
}
Color GetRock() {
	return Rock;
}