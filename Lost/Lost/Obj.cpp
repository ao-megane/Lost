#include"Obj.h"
#include"Value.h"
#include<math.h>

int Dot::Set(int a, int b) {
	x = a;
	y = b;
	return 0;
}
int Dot::Setx(int a) {
	x = a;
	return 0;
}
int Dot::Sety(int a) {
	y = a;
	return 0;
}

int Dot::Get_x() {
	return x;
}

int Dot::Get_y() {
	return y;
}

/***************************************************************/

int Square::Set(Dot a, Dot b) {
	LU = a;
	RD = b;
	return 0;
}
int Square::Set(Dot a, int w, int h) {
	LU.Set(a.Get_x() - w / 2, a.Get_y() - h / 2);
	RD.Set(a.Get_x() + w / 2, a.Get_y() + h / 2);
	return 0;
}
int Square::Set(int a, int b, int c, int d) {
	LU.Set(a, b);
	RD.Set(c, d);
	return 0;
}

int Square::Get_up() {
	return LU.Get_y();
}
int Square::Get_left() {
	return LU.Get_x();
}
Dot Square::Get_LU() {
	return LU;
}
Dot Square::Get_RD() {
	return RD;
}

/******************************************/
int Circle::Set(int a, int b, double c, double d) {
	center.Setx(a);
	center.Sety(b);
	range = c;
	dir = d;
	return 0;
}
int Circle::Set(Dot a, double b, double c) {
	center = a;
	range = b;
	dir = c;
	return 0;
}
int Circle::Move(int dx, int dy) {
	center.Setx(center.Get_x() + dx);
	center.Sety(center.Get_y() + dy);

	if (dx < 0) dir = atan(dy / dx) + PI;
	else if (dx == 0 && dy >= 0)
		dir = 1 / 2 * PI;
	else if (dx == 0 && dy <= 0)
		dir = 3 / 2 * PI;
	else if (dx > 0) 
		dir = atan(dy / dx);

	return 0;
}

