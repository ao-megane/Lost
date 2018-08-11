#ifndef CHORE_H
#define CHORE_H
#include"Obj.h"
#include<string>

//イベント画像、背景画像、UI、等など

int SystemInitialize();

int Floor1Draw();

int Floor2Draw();

int GetFloor1SoftHandle();

int GetLowstepSoftHandle();

int GetHighstepSoftHandle();

int GetFloor2SoftHandle();


int PlayMove();

int PlayChoice();

int* ScorePass();

int DrawOP();

int PlayBGM();

int DrawPrologue(int b);

int DrawManual(int b);

int DrawCredit();

int DrawPause();

//void DrawChore();

int SetBack();
//
//int SetFloor1();
//
//int SetStep1();
//
//int SetStep2();
//
//int SetFloor2();
//
//int UpdataBack();

int DrawBack(int floor,Dot player);

int EndBack();

int InputFile(std::string file);

int DrawData();

int UpdataFile(std::string file,int levelFlag,int score);//呼び出される->一人分の更新

int SetLoser(int levelFlag,int count);

int LoserUpdata(int count);

int DrawLoseBord(int count);

int DrawWinBord(int count);

int SetWinner(int levelFlag,int count,int* score);

int WinnerUpdata(int count);

//bool IsHitColorCtoAll(Circle x,int colorHandle,int imageHandle);

//bool IsHitColorDot(Dot x, int colorHandle, int imageHandle);

double CalcDir(Dot center, Dot a);
double CalcDir(Dot center);

Dot RotateDot(double thita, Dot x, Dot c);

Dot RotateDot(double thita, Dot x);//原点中心

void FpsTimeFanction();

#endif // !CHORE_H
