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

	for (double i = x.GetRadius(); i > 0; i--) {//ˆê”Ô‚¤‚Ü‚­‚¢‚Á‚Ä‚é
		double j = +sqrt(x.GetRadius()*x.GetRadius() - i * i);
		resultDot.Set(i, j);
		resultDot = RotateDot(x.GetDir(), resultDot) + x.GetDot();
		GetPixelSoftImage(Handle, resultDot.Getx(), resultDot.Gety(), &colordecoi[0], &colordecoi[1], &colordecoi[2], 0);
		if (r == colordecoi[0] && g == colordecoi[1] && b == colordecoi[2]) {	//‚Ô‚Â‚©‚ê‚Î
			touchDot = resultDot;
			//DrawCircle(touchDot.Getx(), touchDot.Gety(), 20, RED, 1);
			isHitflag = true;
			break;
		}

		j *= -1;
		resultDot.Set(i, j);
		resultDot = RotateDot(x.GetDir(), resultDot) + x.GetDot();
		GetPixelSoftImage(Handle, resultDot.Getx(), resultDot.Gety(), &colordecoi[0], &colordecoi[1], &colordecoi[2], 0);
		if (r == colordecoi[0] && g == colordecoi[1] && b == colordecoi[2]) {	//‚Ô‚Â‚©‚ê‚Î
			touchDot = resultDot;
			//DrawCircle(touchDot.Getx(), touchDot.Gety(), 20, RED, 1);
			isHitflag = true;
			break;
		}
	}

	if (isHitflag) return true;
	else return false;
	

	/*if(!isHitflag)	//‚¤‚Ü‚­‚¢‚Á‚Ä‚é
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

int PlayerMoveInColor(Circle* x,Dot moveDot) {
	//circle‚Ì’†S‚Æ“–‚½‚Á‚½“_(i,j)‚Åƒ¦‚Æ‚Á‚Äsin‚·‚é
	//DrawFormatString(0, 120, RED, "thtia1:%d", CalcDir(x->GetDot(), touchDot) * 180 / PI);
	thita1 = CalcDir(x->GetDot(), touchDot);
	//DrawFormatString(0, 260, RED, "touchDotthita:%f", thita1*180.0 / PI);
	if (RotateDot(-thita1, moveDot).Getx() > 0) {	//•Ç‚ÉŒü‚©‚Á‚Ä‚¢‚ê‚Î
		resultDot.Set(0, RotateDot(-thita1, moveDot).Gety());
		//DrawFormatString(0, 240, RED, "premove:(%f,%f)", resultDot.Getx(), resultDot.Gety());

		resultDot = RotateDot(thita1, resultDot);
		//DrawFormatString(0, 220, RED, "move:(%f,%f)", resultDot.Getx(), resultDot.Gety());

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

