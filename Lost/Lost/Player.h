#ifndef PLAYER
#define PLAYER

class Player {
private:
	//int Stm;//スタミナ
	//int Max_Stm;
	Circle player;
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
	Player();
	~Player();
	int Initialize();
	int SetPimage(char a[]);
	int SetPcircle;
	double GetSpeed();
	int Updata(int Key[],int flag);
	int Draw();
};



#endif // !PLAYER
