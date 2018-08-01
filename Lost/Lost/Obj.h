#ifndef OBJH
#define OBJH

class Dot{//int型の点
public:/*
	Dot();
	~Dot();*/
	int Setx(int x);
	int Sety(int y);
	int Set(int x,int y);			//左上、右下
	int Getx();
	int Gety();
	
	void operator = (Dot d) {		//Dotの代入
		x = d.Getx();
		y = d.Gety();
	};		
	Dot operator - (Dot d) {		//Dotの平行移動
		Dot a;
		a.x -= d.Getx();
		a.y -= d.Gety();
		return a;
	};		
private:
	int x;
	int y;
};

class Square{//int四つ
public:
	int Set(Dot a, Dot b);
	int Set(Dot a, int w, int h);
	int Set(int a, int b, int c, int d);
	int Getup();
	int Getleft();
	Dot GetLU();
	Dot GetRD();
	void operator - (Dot a) {		//Squareのdot平行移動
		Set(LU - a, RD - a);
	};
	void operator - (int a) {		//Squareのx平行移動
		LU.Setx(LU.Getx() - a);
		RD.Setx(RD.Getx() - a);
	};
	bool operator & (Square a) {	//あたり判定演算子　true で重なってる
	//if (a[2]<b[0] || a[0]>b[2] || a[1] > b[3] || a[3] < b[1]) return 当たってない
		if (RD.Getx() < a.GetLU().Getx() || LU.Getx() > a.RD.Getx() ||
			LU.Gety() > a.GetRD().Gety() || RD.Gety() < a.LU.Gety())
			return false;
		else
			return true;
	};	

private:
	Dot LU;
	Dot RD;
};

class Circle {//方向付き円
public:
	int Set(int x, int y, double range, double dir);
	int Set(Dot a, double range, double dir);
	int Move(double dx, double dy);
	int Back(double dx, double dy);
	Dot GetDot();
	int Getx();
	int Gety();
	double GetDir();
	double GetRadius();
	//int Updata();

private:
	double radius;
	double dir;	//0~2PI
	Dot center;
};


#endif // !OBJH
