#ifndef PLAYER
#define PLAYER
#include"Obj.h"

class Player {
private:
	//int Stm;//スタミナ
	//int Max_Stm;
	Circle player;
	Dot move;
	bool rEye;	//trueで持ってる
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
	int bodyClock;	//アニメ用クロック，音にも使う
	int animeNum;	//アニメ用クロックの結果 0~2
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
	int Updata(int Key[],int flag);
	int keyGet();
	bool GetKeyflag();
	bool isGameOver();
	int Draw();
	int DrawMask();
	int UIDraw(int count);
	bool isEar();
	bool isArm();
};

int PlayPWalk();
int yesPSounds();
int noPSounds();


#endif // !PLAYER
