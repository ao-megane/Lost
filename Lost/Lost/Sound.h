#ifndef SOUND_H
#define SOUND_H
//本当に音を鳴らすのではなく，ゲーム内の音のビジュアライズをつかさどる
#include"Obj.h"
#include"DxLib.h"
#include"Value.h"

class Sound {//方向付き円
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
	int keepCount;	//発生時のカウント
	double speed;	//1fに何px大きくなるか
	int lifeSpan;	//何fで消えるか
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
