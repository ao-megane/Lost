#ifndef ENEMYMNG_H
#define ENEMYMNG_H
#include"Chore.h"
#include"Obj.h"
#include"Player.h"

class Enemy{
public:
	/*Enemy();
	~Enemy();*/
	//int Updata(int count);	//�L�������Ƃɍ��
	int Draw(Dot player);		//�`��
	Dot GetMove();
	int UpdataMove(Dot Destination);
	//int End();

protected:
	Circle enemy;		//�����t���~�C�`��Ɠ����蔻��
	Square serch;		//�T���͈�(�l�p)
	Dot move;			//�i�s�����I��
	Dot dest;			//�ړI�n�I�� move�ɓn������K�v�͂Ȃ� debug�p
	//bool ischase;		//�v���C���[��ǂ��Ă��邩
	int nextNum;		//dest�̒ʂ��ԍ�,0base
	int stateflag;		//0�ۏ� 1���� 2�v���C���[�ڎ� 3�v���C���[������
	double Speed;		//�Ȃ��̃X�s�[�h
	int image[8];		//�A�j���[�V�����p
	int Eimage;
};

class Husband : public Enemy
{
public:
	int Initialize();
	int Set(); //�o����(���X�|�[����)����,�ʒu�ς��邾��
	int Updata(Circle player);	//�ϐ��œ����������Ԃ�����
private:
};

class Madam : public Enemy
{
public:
	int Initialize();
	int Set(); //�o����(���X�|�[����)����,�ʒu�ς��邾��
	int Updata(Circle player);	//�ϐ��œ����������Ԃ�����
private:
};

class Son : public Enemy
{
public:
	int Initialize();
	int Set(); //�o����(���X�|�[����)����,�ʒu�ς��邾��
	int Updata(Circle player);	//�ϐ��œ����������Ԃ�����
	Dot GetDest();
	int GetState();
	int GetNextNum();
private:
};

class Daughter : public Enemy
{
public:
	int Initialize();
	int Set(); //�o����(���X�|�[����)����,�ʒu�ς��邾��
	int Updata(Circle player);	//�ϐ��œ����������Ԃ�����
private:
};


int EnemyMngInitialize();			//�摜�n���h������
int EnemyMngSet();	//�X�e�[�W�A���Ԃ��Ƃɔz�u
int EnemyMngUpdata(Circle player,int floor);		//�ϐ��łǂ���������邩�Ԃ�
//int EnemyMngJudge(Player* player,int count,int* score,int levelFlag);	//����Astate�AHP���̍X�V
int EnemyMngDraw(Dot player,int floor);


#endif // !ENEMYMNG_H
