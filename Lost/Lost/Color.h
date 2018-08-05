#ifndef COLOR_H
#define COLOR_H

class Color
{
public:/*
	Color();
	~Color();*/
	int Initialize(int r, int g, int b);
	int GetColorori();
	bool IsHitPlayer(Circle* x, int softimageHandle,Dot moveDot);
	bool IsHitCircle(Circle x, int softimageHandle);
	bool IsHitDot(Dot x, int softimageHandle);

private:
	int r;
	int g;
	int b;
};

//Color::Color()
//{
//}
//
//Color::~Color()
//{
//}


#endif // !COLOR_H
