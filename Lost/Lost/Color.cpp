#include"DxLib.h"
#include"Obj.h"
#include"Color.h"
#include"Value.h"

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
bool Color::IsHitPlayer(Circle x, int Handle) {
	isHitflag = false;
	if (Handle == 0)
		return false;
	for (double i = x.Getx() - x.GetRadius()- JUDGE_MARGIN * P_FULL_SPEED; i < x.Getx() + x.GetRadius() + JUDGE_MARGIN*P_FULL_SPEED; i++) {
		for (double j = x.Gety() - x.GetRadius() - JUDGE_MARGIN * P_FULL_SPEED; j < x.Gety() + x.GetRadius() + JUDGE_MARGIN * P_FULL_SPEED; j++) {
			if (((i - x.Getx())*(i - x.Getx()) + (j - x.Gety())*(j - x.Gety())) <= (x.GetRadius() + JUDGE_MARGIN * P_FULL_SPEED)*(x.GetRadius() + JUDGE_MARGIN*P_FULL_SPEED) &&
				((i - x.Getx())*(i - x.Getx()) + (j - x.Gety())*(j - x.Gety())) >= (x.GetRadius())*(x.GetRadius())) {
				GetPixelSoftImage(Handle, i, j, &colordecoi[0], &colordecoi[1], &colordecoi[2], 0);
				DrawPixel(i, j, BLUE);
				if (r == colordecoi[0] && g == colordecoi[1] && b == colordecoi[2])
					isHitflag =  true;
			}
		}
	}
	if (isHitflag) return true;
	else return false;
	return false;
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

