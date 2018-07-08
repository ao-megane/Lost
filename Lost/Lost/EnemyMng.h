#ifndef ENEMYMNG_H
#define ENEMYMNG_H
#include"Chore.h"
#include"Player.h"

class Enemy
{
public:
	/*Enemy();
	~Enemy();*/
	//int Updata(int count);	//キャラごとに作る
	//int Draw();			//描画
	/*int GetExistFlag();
	int SetHP(int a);
	int SetAttackval(int a);
	int GetHP();
	int GetAttack();
	int GetStartClock();
	int GetStateFlag();
	int GetBodyClock();
	int GetHeight();
	int GetWidth();
	int GetStrength();
	int PlayDamage();
	int pDirFlag;
	Dot GetCenter();
	Square GetWeekArea();
	Square GetAttackArea();
	void SetExistFlag(int i);*/
	//int End();

protected:
	Circle enemy;
	int Image;			//現在の画像
	int bodyClock;		//アニメーション用体内時計
	int startClock;		//出現時時間
	int dirFlag;		//向いてる方向フラグ（1で右 0で左）
};
/*
void SlimeMngInitialize();
class Slime : public Enemy
{
public:
	void Initialize();
	int Set(int count,int position,int strength); //出現時処理
	int SetStand(int count);
	int UpdataStand(int count);
	int SetJump(int count);
	int UpdataJump(int count);
	int SetDamage(int count, int damage);
	int UpdataDamage(int count);
	int SetDisapper(int count);
	int UpdataDisapper(int count);
	int Updata(int count);
	int Draw();			//描画
private:
};
*/
//int SlimeMngSet(int count,int dirFlag,int level);

//int EnemyMngInitialize();			//画像ハンドル周り
//void EnemyMngInitialize(int i);
//int EnemyMngSet(int levelFlag, int count,Dot girl);	//ステージ、時間ごとに配置
//int EnemyMngUpdata(int count);		//移動やらアニメやら、攻撃に入るのはJudgeで行う
//int EnemyMngJudge(Player* player, Princess* girl,int count,int* score,int levelFlag);	//判定、state、HP等の更新
//int EnemyMngDraw();


#endif // !ENEMYMNG_H
