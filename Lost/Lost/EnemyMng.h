#ifndef ENEMYMNG_H
#define ENEMYMNG_H
#include"Chore.h"
#include"Obj.h"
#include"Player.h"

class Enemy{
public:
	/*Enemy();
	~Enemy();*/
	//int Updata(int count);	//キャラごとに作る
	int Draw(Dot player);		//描画
	Dot GetMove();
	int UpdataMove(Dot Destination);
	//int End();

protected:
	Circle enemy;		//方向付き円，描画と当たり判定
	Square serch;		//探索範囲(四角)
	Dot move;			//進行方向的な
	Dot dest;			//目的地的な moveに渡すから必要はない debug用
	//bool ischase;		//プレイヤーを追っているか
	int nextNum;		//destの通し番号,0base
	int stateflag;		//0塁上 1走塁 2プレイヤー目視 3プレイヤー見失い
	double Speed;		//なうのスピード
	int image[8];		//アニメーション用
	int Eimage;
};

class Husband : public Enemy
{
public:
	int Initialize();
	int Set(); //出現時(リスポーン時)処理,位置変えるだけ
	int Updata(Circle player);	//変数で当たったか返す感じ
private:
};

class Madam : public Enemy
{
public:
	int Initialize();
	int Set(); //出現時(リスポーン時)処理,位置変えるだけ
	int Updata(Circle player);	//変数で当たったか返す感じ
private:
};

class Son : public Enemy
{
public:
	int Initialize();
	int Set(); //出現時(リスポーン時)処理,位置変えるだけ
	int Updata(Circle player);	//変数で当たったか返す感じ
	Dot GetDest();
	int GetState();
	int GetNextNum();
private:
};

class Daughter : public Enemy
{
public:
	int Initialize();
	int Set(); //出現時(リスポーン時)処理,位置変えるだけ
	int Updata(Circle player);	//変数で当たったか返す感じ
private:
};


int EnemyMngInitialize();			//画像ハンドル周り
int EnemyMngSet();	//ステージ、時間ごとに配置
int EnemyMngUpdata(Circle player,int floor);		//変数でどこをもがれるか返す
//int EnemyMngJudge(Player* player,int count,int* score,int levelFlag);	//判定、state、HP等の更新
int EnemyMngDraw(Dot player,int floor);


#endif // !ENEMYMNG_H
