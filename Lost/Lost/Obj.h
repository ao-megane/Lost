#ifndef OBJ_H
#define OBJ_H

class Dot{//int型の点
public:/*
	Dot();
	~Dot();*/
	int Setx(int x);
	int Sety(int y);
	int Set(int x,int y);			//左上、右下
	int Get_x();
	int Get_y();
	
	void operator = (Dot d) {		//Dotの代入
		x = d.Get_x();
		y = d.Get_y();
	};		
	Dot operator - (Dot d) {		//Dotの平行移動
		Dot a;
		a.x -= d.Get_x();
		a.y -= d.Get_y();
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
	int Get_up();
	int Get_left();
	Dot Get_LU();
	Dot Get_RD();
	void operator - (Dot a) {		//Squareのdot平行移動
		Set(LU - a, RD - a);
	};
	void operator - (int a) {		//Squareのx平行移動
		LU.Setx(LU.Get_x() - a);
		RD.Setx(RD.Get_x() - a);
	};
	bool operator & (Square a) {	//あたり判定演算子　true で重なってる
	//if (a[2]<b[0] || a[0]>b[2] || a[1] > b[3] || a[3] < b[1]) return 当たってない
		if (RD.Get_x() < a.Get_LU().Get_x() || LU.Get_x() > a.RD.Get_x() ||
			LU.Get_y() > a.Get_RD().Get_y() || RD.Get_y() < a.LU.Get_y())
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
	int Move(int dx, int dy);

private:
	double range;
	double dir;	//0~2PI
	Dot center;
};


#endif // !OBJ_H
