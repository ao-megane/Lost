#ifndef ENEMYMNG_H
#define ENEMYMNG_H
#include"Chore.h"
#include"Player.h"

class Enemy
{
public:
	/*Enemy();
	~Enemy();*/
	//int Updata(int count);	//�L�������Ƃɍ��
	//int Draw();			//�`��
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
	int Image;			//���݂̉摜
	int bodyClock;		//�A�j���[�V�����p�̓����v
	int startClock;		//�o��������
	int dirFlag;		//�����Ă�����t���O�i1�ŉE 0�ō��j
};
/*
void SlimeMngInitialize();
class Slime : public Enemy
{
public:
	void Initialize();
	int Set(int count,int position,int strength); //�o��������
	int SetStand(int count);
	int UpdataStand(int count);
	int SetJump(int count);
	int UpdataJump(int count);
	int SetDamage(int count, int damage);
	int UpdataDamage(int count);
	int SetDisapper(int count);
	int UpdataDisapper(int count);
	int Updata(int count);
	int Draw();			//�`��
private:
};
*/
//int SlimeMngSet(int count,int dirFlag,int level);

//int EnemyMngInitialize();			//�摜�n���h������
//void EnemyMngInitialize(int i);
//int EnemyMngSet(int levelFlag, int count,Dot girl);	//�X�e�[�W�A���Ԃ��Ƃɔz�u
//int EnemyMngUpdata(int count);		//�ړ����A�j�����A�U���ɓ���̂�Judge�ōs��
//int EnemyMngJudge(Player* player, Princess* girl,int count,int* score,int levelFlag);	//����Astate�AHP���̍X�V
//int EnemyMngDraw();


#endif // !ENEMYMNG_H
