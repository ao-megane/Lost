#ifndef ENEMYMNG_H
#define ENEMYMNG_H
#include"Chore.h"
#include"Obj.h"
#include"Player.h"
#include"Sound.h"

class Enemy{
public:
	/*Enemy();
	~Enemy();*/
	int Set(int speed,int floor);
	int Updata(Circle player,int floor,int halfSpeed,int fullSpeed,int flag,int count,SoundMng psound);	//0 son 1 daughter 2 husband 3 madam
	int SoundDraw(Circle player,int count,int flag);
	int Draw(Dot player);		//描画
	Dot GetMove();
	int UpdataMove(Dot Destination);
	//int End();

protected:
	Circle enemy;		//方向付き円，描画と当たり判定
	Square serch;		//探索範囲(四角)
	Dot move;			//進行方向的な
	Dot dest;			//目的地的な moveに渡すから必要はない debug用
	SoundMng esound;
	int nextNum;		//destの通し番号,0base
	int stateflag;		//0塁上 1走塁 2プレイヤー目視 3プレイヤー見失い
	double Speed;		//なうのスピード
	int bodyClock;
	int animeNum;
	int image[12];		//アニメーション用
	int EWalkUp[3];
	int EWalkDown[3];
	int EWalkRight[3];
	int EWalkLeft[3];
	int Eimage;
};

class Husband : public Enemy
{
public:
	int Initialize();
	//int Updata(Circle player);	//変数で当たったか返す感じ
	int GetState();
	int GetNextNum();
private:
};

class Madam : public Enemy
{
public:
	int Initialize();
	//int Updata(Circle player);	//変数で当たったか返す感じ
private:
};

class Son : public Enemy
{
public:
	int Initialize();
	//int Updata(Circle player);	//変数で当たったか返す感じ
	Dot GetDest();
	int GetState();
	int GetNextNum();
private:
};

class Daughter : public Enemy
{
public:
	int Initialize();
	//int Updata(Circle player);	//変数で当たったか返す感じ
private:
};


int EnemyMngInitialize();			//画像ハンドル周り
int EnemyMngSet();	//ステージ、時間ごとに配置
int EnemyMngUpdata(Circle player,int floor,int count,SoundMng psound);		//変数でどこをもがれるか返す
//int EnemyMngJudge(Player* player,int count,int* score,int levelFlag);	//判定、state、HP等の更新
int EnemyMngSoundDraw(Circle player, int count,int flag);
int EnemyMngDraw(Dot player,int floor);

int PlaySonWalk();
int PlayDaughterWalk();
int PlayHusbandWalk();
int PlayMadamWalk();

int yesESounds();
int noESounds();

#endif // !ENEMYMNG_H
