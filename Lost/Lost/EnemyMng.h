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
	int Draw();			//�`��
	//int End();

protected:
	Circle enemy;		//�����t���~�C�`��Ɠ����蔻��
	int Floor;			//1or2�K�ɂ���D�`��p��
	int image[8];			//�A�j���[�V�����p
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
int EnemyMngDraw(int floor);


#endif // !ENEMYMNG_H
