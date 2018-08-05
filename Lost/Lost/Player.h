#ifndef PLAYER
#define PLAYER
#include"Obj.h"

class Player {
private:
	//int Stm;//スタミナ
	//int Max_Stm;
	Circle player;
	Dot move;
	bool rEye;
	bool lEye;
	bool rArm;
	bool lArm;
	bool rEar;
	bool lEar;
	bool rLeg;
	bool lLeg;
	double Speed;
	int Pimage;
public:
	//Player();
	//~Player();
	int Initialize();
	int Set();
	int Reborn();
	int SetPimage(int imageHandle);
	int UpdataMove(double x,double y);
	double GetSpeed();
	Circle Getplayer();
	Dot GetMove();
	int Updata(int Key[],int flag);
	int Draw();
	int UIDraw(int count);
};



#endif // !PLAYER
