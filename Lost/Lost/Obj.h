#ifndef OBJ_H
#define OBJ_H

class Dot{//int�^�̓_
public:/*
	Dot();
	~Dot();*/
	int Setx(int x);
	int Sety(int y);
	int Set(int x,int y);			//����A�E��
	int Get_x();
	int Get_y();
	
	void operator = (Dot d) {		//Dot�̑��
		x = d.Get_x();
		y = d.Get_y();
	};		
	Dot operator - (Dot d) {		//Dot�̕��s�ړ�
		Dot a;
		a.x -= d.Get_x();
		a.y -= d.Get_y();
		return a;
	};		
private:
	int x;
	int y;
};

class Square{//int�l��
public:
	int Set(Dot a, Dot b);
	int Set(Dot a, int w, int h);
	int Set(int a, int b, int c, int d);
	int Get_up();
	int Get_left();
	Dot Get_LU();
	Dot Get_RD();
	void operator - (Dot a) {		//Square��dot���s�ړ�
		Set(LU - a, RD - a);
	};
	void operator - (int a) {		//Square��x���s�ړ�
		LU.Setx(LU.Get_x() - a);
		RD.Setx(RD.Get_x() - a);
	};
	bool operator & (Square a) {	//�����蔻�艉�Z�q�@true �ŏd�Ȃ��Ă�
	//if (a[2]<b[0] || a[0]>b[2] || a[1] > b[3] || a[3] < b[1]) return �������ĂȂ�
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

class Circle {//�����t���~
public:
	int Set(int x, int y, double range, double dir);
	int Set(Dot a, double range, double dir);
	int Move(int dx, int dy);
	Dot GetDot();
	int Getx();
	int Gety();
	double GetRadius();

private:
	double radius;
	double dir;	//0~2PI
	Dot center;
};


#endif // !OBJ_H
