#ifndef SOUND_H
#define SOUND_H
//�{���ɉ���炷�̂ł͂Ȃ��C�Q�[�����̉��̃r�W���A���C�Y�������ǂ�
#include"Obj.h"
#include"DxLib.h"
#include"Value.h"

class Sound {//�����t���~
public:
	int Set(int x, int y, double speed,int lifeSpan,int count);
	int Set(Dot a, double speed,int lifeSpan, int count);
	Dot GetDot();
	int Getx();
	int Gety();
	double GetRadius(int count);
	int Draw(Dot player,int count,int handle);
	//int Updata();
	/*bool operator & (Circle a) {
		if (sqrt(
			(center.Getx() - a.GetDot().Getx())*(center.Getx() - a.GetDot().Getx()) +
			(center.Gety() - a.GetDot().Gety())*(center.Gety() - a.GetDot().Gety())
		)
			<= radius + a.GetRadius())
			return true;
		else
			return false;
	};*/

private:
	int keepCount;	//�������̃J�E���g
	double speed;	//1f�ɉ�px�傫���Ȃ邩
	int lifeSpan;	//��f�ŏ����邩
	Dot center;
};

class SoundMng {
public:
	int Initialzie();
	int Born(Dot dot, int speed,int lifespan,int count);
	int Draw(Dot player);
private:
	Sound sound[10];
	int num;
};

#endif // !SOUND_H
