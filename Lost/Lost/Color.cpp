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
int Color::GetColorori() {
	return GetColor(r, g, b);
}
int colordecoi[3];	//r,g,b
bool isHitflag;
double thita1;
double thita2;
Dot touchDot;
Dot resultDot;
bool Color::IsHitPlayer(Circle* x, int Handle,Dot moveDot) {
	isHitflag = false;
	thita1 = CalcDir(moveDot);
	if (Handle == 0)
		return false;

	if (!isHitflag)	//一番うまくいってる
		for (double i = x->GetRadius(); i > 0; i--) {
			double j = +sqrt(x->GetRadius()*x->GetRadius() - i * i);
			resultDot.Set(i, j);
			resultDot = RotateDot(thita1, resultDot) + x->GetDot();
			GetPixelSoftImage(Handle, resultDot.Getx(), resultDot.Gety(), &colordecoi[0], &colordecoi[1], &colordecoi[2], 0);
			if (r == colordecoi[0] && g == colordecoi[1] && b == colordecoi[2]) {
				touchDot = resultDot;
				//DrawCircle(i, j, 20, RED, 1);
				isHitflag = true;
				break;
			}

			j *= -1;
			resultDot.Set(i, j);
			resultDot = RotateDot(-thita1, resultDot) + x->GetDot();
			GetPixelSoftImage(Handle, resultDot.Getx(), resultDot.Gety(), &colordecoi[0], &colordecoi[1], &colordecoi[2], 0);
			if (r == colordecoi[0] && g == colordecoi[1] && b == colordecoi[2]) {
				touchDot = resultDot;
				//DrawCircle(i, j, 20, RED, 1);
				isHitflag = true;
				break;
			}
		}
	

	/*if(!isHitflag)	//一番うまくいってる
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

	thita2 = CalcDir(moveDot);
	if (isHitflag) {//circleの中心と当たった点(i,j)でΘとってsinする
		//DrawFormatString(0, 120, RED, "thtia1:%d", CalcDir(x->GetDot(), touchDot) * 180 / PI);
		thita1 = CalcDir(x->GetDot(), touchDot);
		DrawFormatString(0, 260, RED, "touchDotthita:%f", thita1*180.0 / PI);
		if (RotateDot(-thita1, moveDot).Getx() > 0) {	//壁に向かっていれば
			resultDot.Set(0, RotateDot(-thita1, moveDot).Gety());
			DrawFormatString(0, 240, RED, "premove:(%f,%f)", resultDot.Getx(), resultDot.Gety());

			resultDot = RotateDot(thita1, resultDot);
			DrawFormatString(0, 220, RED, "move:(%f,%f)", resultDot.Getx(), resultDot.Gety());

			x->Move(resultDot.Getx(), resultDot.Gety());
			x->SetDir(thita2);
		}
		else {
			x->Move(moveDot.Getx(), moveDot.Gety());
			x->SetDir(thita2);
		}
		return true;
	}
	else {
		x->Move(moveDot.Getx(), moveDot.Gety());
		x->SetDir(thita2);
		return false;
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

