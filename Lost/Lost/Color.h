#ifndef COLOR_H
#define COLOR_H
#include"Obj.h"

class Color
{
public:/*
	Color();
	~Color();*/
	int Initialize(int r, int g, int b);
	int GetColorOri();
	bool IsHitMoving(Circle x, int softimageHandle);
	bool IsHitCircle(Circle x, int softimageHandle);
	bool IsHitDot(Dot x, int softimageHandle);
	bool IsHitDottoDot(Dot a, Dot b, int softimageHandle);

private:
	int r;
	int g;
	int b;
};

int PlayerMoveInColor(Circle* x,Dot moveDot);

int ColorMngInitialize();

Color GetWall();

Color GetDoor();

Color GetFloor1();

Color GetFloor2();

Color GetLowstep();

Color GetHighstep();

Color GetRock();

//Color::Color()
//{
//}
//
//Color::~Color()
//{
//}


#endif // !COLOR_H
