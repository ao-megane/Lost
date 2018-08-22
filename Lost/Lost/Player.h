#ifndef PLAYER
#define PLAYER
#include"Obj.h"
#include"Sound.h"

class Player {
private:
	//int Stm;//�X�^�~�i
	//int Max_Stm;
	Circle player;
	Dot move;
	bool rEye;	//true�Ŏ����Ă�
	bool lEye;
	bool rArm;
	bool lArm;
	bool rEar;
	bool lEar;
	bool rLeg;
	bool lLeg;
	bool havekey;
	double Speed;
	int floor;
	int bodyClock;	//�A�j���p�N���b�N�C���ɂ��g��
	int animeNum;	//�A�j���p�N���b�N�̌��� 0~2
	int Pimage;
public:
	//Player();
	//~Player();
	int Initialize();
	int Set();
	int Reborn();
	int SetPimage(int imageHandle);
	int UpdataMove(double x,double y);
	int GetFloor();	//1.2.3.4.
	int SetFloor(int a);
	double GetSpeed();
	int LostEye();
	int LostLeg();
	int LostEar();
	int LostArm();
	Dot GetDot();
	int SetSpeed(double a);
	Circle GetCircle();
	Dot GetMove();
	int Updata(int Key[],int flag,int count);
	int keyGet();
	bool GetKeyflag();
	bool isGameOver();
	int SoundDraw(int count);
	int Draw();
	int DrawMask();
	int DrawEarMask();
	int UIDraw(int count);
	int GetEarflag();
	bool isEar();
	bool isArm();
};

SoundMng Getpsound();
int PlayPWalk();
int yesPSounds();
int noPSounds();


#endif // !PLAYER
