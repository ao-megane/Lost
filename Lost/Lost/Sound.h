#ifndef SOUND_H
#define SOUND_H
//本当に音を鳴らすのではなく，ゲーム内の音のビジュアライズをつかさどる
#include"Obj.h"
#include"DxLib.h"
#include"Value.h"
#include"Chore.h"

class Sound {//方向付き円
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
	int Draw(Circle player,int count,int handle,int flag);//0 両耳ある　1　右耳のみ　2　左耳のみ 3 両耳ない
	bool isHitDot(Dot a,int count);

private:
	int keepCount;	//発生時のカウント
	double speed;	//1fに何px大きくなるか
	double lifeSpan;	//何fで消えるか
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
