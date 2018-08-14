#include"Obj.h"
#include"Value.h"
#include"Chore.h"
#include<math.h>

int intDot::Set(int a, int b) {
	x = a;
	y = b;
	return 0;
}
int intDot::Setx(int a) {
	x = a;
	return 0;
}
int intDot::Sety(int a) {
	y = a;
	return 0;
}

int intDot::Getx() {
	return x;
}

int intDot::Gety() {
	return y;
}

/***************************************************************/
double Dot::Set(double a, double b) {
	x = a;
	y = b;
	return 0;
}
double Dot::Setx(double a) {
	x = a;
	return 0;
}
double Dot::Sety(double a) {
	y = a;
	return 0;
}

double Dot::Getx() {
	return x;
}

double Dot::Gety() {
	return y;
}




/***************************************************************/

int Square::Set(Dot a, Dot b,double c) {
	LU = a;
	RD = b;
	dir = c;
	return 0;
}
int Square::Set(Dot a,Dot b) {
	LU = a;
	RD = b;
	return 0;
}
int Square::Set(Dot a, int w, int h,double c) {
	LU.Set(a.Getx() - w / 2, a.Gety() - h / 2);
	RD.Set(a.Getx() + w / 2, a.Gety() + h / 2);
	dir = c;
	return 0;
}
int Square::Set(int a, int b, int c, int d,double thita) {
	LU.Set(a, b);
	RD.Set(c, d);
	dir = thita;
	return 0;
}
Dot decoi_obj[4];
Dot center_obj;
int Square::Draw(int handle) {
	center_obj.Set(LU.Getx(), RD.Gety() / 2);
	decoi_obj[0] = LU;
	decoi_obj[0] = RotateDot(dir, decoi_obj[0], center_obj);

	decoi_obj[1].Setx(RD.Getx());
	decoi_obj[1].Sety(LU.Gety());
	decoi_obj[1] = RotateDot(dir, decoi_obj[1], center_obj);

	decoi_obj[2] = RD;
	decoi_obj[2] = RotateDot(dir, decoi_obj[2], center_obj);

	decoi_obj[3].Setx(LU.Getx());
	decoi_obj[3].Sety(RD.Gety());
	decoi_obj[3] = RotateDot(dir, decoi_obj[3], center_obj);

	DrawLineByDot(decoi_obj[0], decoi_obj[1], handle);
	DrawLineByDot(decoi_obj[1], decoi_obj[2], handle);
	DrawLineByDot(decoi_obj[2], decoi_obj[3], handle);
	DrawLineByDot(decoi_obj[3], decoi_obj[0], handle);

	return 0;
}

int Square::Getup() {
	return LU.Gety();
}
int Square::Getleft() {
	return LU.Getx();
}
Dot Square::GetLU() {
	return LU;
}
Dot Square::GetRD() {
	return RD;
}

/******************************************/
int Circle::Set(int a, int b, double c, double d) {
	center.Setx(a);
	center.Sety(b);
	radius= c;
	dir = d;
	return 0;
}
int Circle::Set(Dot a, double b, double c) {
	center = a;
	radius = b;
	dir = c;
	return 0;
}
int Circle::SetDir(double a){
	dir = a;
	return 0;
}
int Circle::Move(double dx, double dy) {
	center.Setx(center.Getx() + dx);
	center.Sety(center.Gety() + dy);
	return 0;
}
int Circle::MoveandTurn(double dx, double dy) {
	if (dx == 0 && dy == 0) return 0;
	center.Setx(center.Getx() + dx);
	center.Sety(center.Gety() + dy);

	if (dx < 0) dir = atan(-dy / dx) + PI;
	else if (dx == 0 && -dy >= 0)
		dir = 1 / 2 * PI;
	else if (dx == 0 && -dy <= 0)
		dir = 3 / 2 * PI;
	else if (dx > 0) dir = atan(-dy / dx);

	while (dir < 0) dir += 2 * PI;

	return 0;
}
int Circle::Move(Dot a) {
	center.Setx(center.Getx() + a.Getx());
	center.Sety(center.Gety() + a.Gety());
	return 0;
}
int Circle::MoveandTurn(Dot a) {
	if (a.Getx() == 0 && a.Gety() == 0) return 0;
	center.Setx(center.Getx() + a.Getx());
	center.Sety(center.Gety() + a.Gety());

	if (a.Getx() < 0) dir = atan(-a.Gety() / a.Getx()) + PI;
	else if (a.Getx() == 0 && -a.Gety() >= 0)
		dir = 1 / 2 * PI;
	else if (a.Getx() == 0 && -a.Gety() <= 0)
		dir = 3 / 2 * PI;
	else if (a.Getx() > 0) dir = atan(-a.Gety() / a.Getx());

	while (dir < 0) dir += 2 * PI;

	return 0;
}
int Circle::Back(double dx, double dy) {
	center.Setx(center.Getx() - dx);
	center.Sety(center.Gety() - dy);
	return 0;
}
Dot Circle::GetDot() {
	return center;
}
int Circle::Getx() {
	return center.Getx();
}
int Circle::Gety() {
	return center.Gety();
}
double Circle::GetDir() {
	return dir;
}
double Circle::GetRadius() {
	return radius;
}

