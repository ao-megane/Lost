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
	int Draw(Dot player);		//�`��
	Dot GetMove();
	int UpdataMove(Dot Destination);
	//int End();

protected:
	Circle enemy;		//�����t���~�C�`��Ɠ����蔻��
	Square serch;		//�T���͈�(�l�p)
	Dot move;			//�i�s�����I��
	Dot dest;			//�ړI�n�I�� move�ɓn������K�v�͂Ȃ� debug�p
	SoundMng esound;
	int nextNum;		//dest�̒ʂ��ԍ�,0base
	int stateflag;		//0�ۏ� 1���� 2�v���C���[�ڎ� 3�v���C���[������
	double Speed;		//�Ȃ��̃X�s�[�h
	int bodyClock;
	int animeNum;
	int image[12];		//�A�j���[�V�����p
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
	//int Updata(Circle player);	//�ϐ��œ����������Ԃ�����
	int GetState();
	int GetNextNum();
private:
};

class Madam : public Enemy
{
public:
	int Initialize();
	//int Updata(Circle player);	//�ϐ��œ����������Ԃ�����
private:
};

class Son : public Enemy
{
public:
	int Initialize();
	//int Updata(Circle player);	//�ϐ��œ����������Ԃ�����
	Dot GetDest();
	int GetState();
	int GetNextNum();
private:
};

class Daughter : public Enemy
{
public:
	int Initialize();
	//int Updata(Circle player);	//�ϐ��œ����������Ԃ�����
private:
};


int EnemyMngInitialize();			//�摜�n���h������
int EnemyMngSet();	//�X�e�[�W�A���Ԃ��Ƃɔz�u
int EnemyMngUpdata(Circle player,int floor,int count,SoundMng psound);		//�ϐ��łǂ���������邩�Ԃ�
//int EnemyMngJudge(Player* player,int count,int* score,int levelFlag);	//����Astate�AHP���̍X�V
int EnemyMngSoundDraw(Circle player, int count,int flag);
int EnemyMngDraw(Dot player,int floor);

int PlaySonWalk();
int PlayDaughterWalk();
int PlayHusbandWalk();
int PlayMadamWalk();

int yesESounds();
int noESounds();

#endif // !ENEMYMNG_H
