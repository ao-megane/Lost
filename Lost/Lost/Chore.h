#ifndef CHORE_H
#define CHORE_H
#include"Obj.h"
#include<string>

//イベント画像、背景画像、UI、等など

int SystemInitialize();

int Floor1Draw();

int Floor2Draw();

int PlayMove();

int PlayChoice();

int ChoreSet(int levelFlag);

int* ScorePass();

int PlayBGM();

int DrawOP();

int DrawPrologue(int b);

int DrawManual(int b);

int DrawCredit();

int DrawPause(int count);

void DrawChore(int count, int HP,int levelFlag);

int SetBack(int stageFlag);

int UpdataBack(int count);

int DrawBack();

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

void FpsTimeFanction();

#endif // !CHORE_H
