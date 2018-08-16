#ifndef KEY_H
#define KEY_H
#include"Obj.h"

int KeyInitialize();

int SetKeyPosi();

int GetKeyFloor();

Circle GetKeyCircle();

int KeyDraw(Dot player,int floor);

int PlayKeyPickup();

int PlayKeyUnlock();

#endif // !KEY_H
