#ifndef COLOR_H
#define COLOR_H

class Color
{
public:/*
	Color();
	~Color();*/
	int Initialize(int r, int g, int b);
	int GetColorOri();
	bool IsHitMoving(Circle x, int softimageHandle,Dot moveDot);
	bool IsHitCircle(Circle x, int softimageHandle);
	bool IsHitDot(Dot x, int softimageHandle);

private:
	int r;
	int g;
	int b;
};

int PlayerMoveInColor(Circle* x,Dot moveDot);

//Color::Color()
//{
//}
//
//Color::~Color()
//{
//}


#endif // !COLOR_H
