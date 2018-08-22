#ifndef SOUND_H
#define SOUND_H
//�{���ɉ���炷�̂ł͂Ȃ��C�Q�[�����̉��̃r�W���A���C�Y�������ǂ�
#include"Obj.h"
#include"DxLib.h"
#include"Value.h"
#include"Chore.h"

class Sound {//�����t���~
public:
	int Initialize();
	int Set(int x, int y, double speed,double lifeSpan,int count);
	int Set(Dot a, double speed,double lifeSpan, int count);
	Dot GetDot();
	int Getx();
	int Gety();
	double GetRadius(int count);
	int GetLifeSpan();
	int GetKeepCount();
	int Draw(Circle player,int count,int handle,int flag);//0 ��������@1�@�E���̂݁@2�@�����̂� 3 �����Ȃ�
	bool isHitDot(Dot a,int count);

private:
	int keepCount;	//�������̃J�E���g
	double speed;	//1f�ɉ�px�傫���Ȃ邩
	double lifeSpan;	//��f�ŏ����邩
	Dot center;
};

class SoundMng {
public:
	int Initialzie();
	int Born(Dot dot, double speed,double lifespan,int count);
	int Draw(Circle player,int count,int handle,int flag);
	bool isHitDot(Dot a,int count);
private:
	Sound sound[20];
	//int num;
};

#endif // !SOUND_H
