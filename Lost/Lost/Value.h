#ifndef VALUE_H
#define VALUE_H
#include"dxlib.h"
#include"Color.h"

#define PI 3.1415926535

const int RED = GetColor(255, 0, 0);
const int GREEN = GetColor(0, 255, 0);
const int BLUE = GetColor(0, 0, 255);
const int BLACK = GetColor(0, 0, 0);
const int GRAY = GetColor(127, 127, 127);
const int WHITE = GetColor(255, 255, 255);
const int ORANGE = GetColor(243, 152, 0);
const int BROWN = GetColor(46, 33, 13);

#define A (Key[0])
#define B (Key[1])
#define X (Key[2])
#define Y (Key[3])
#define RIGHT (Key[4])
#define LEFT (Key[5])
#define R_TRIG (Key[6]) //Trigから加算を始める
#define L_TRIG (Key[7]) //Trigから加算を始める
#define THUMB_Y (Key[8])//-100～+100 100が最大値
#define THUMB_X (Key[9]) //-100～+100 100が最大値
#define PAUSE (Key[10])

const int Trig = 200; //R2L2のカウントを始めるしきい値
const int ThumbTrig = 16383; //thumbの無視する範囲 ～32767

const int DISP_WIDTH = 2160;	//画面の大きさ(Surfacepro3)
const int DISP_HEIGHT = 1440;

const int MAP_WIDTH = 5500;
const int MAP_HEIGHT = 3700;

const int MASK_WIDTH = 2600;

const double JUDGE_MARGIN = 1.0;	//プレイヤーと壁の追突について，埋め込まれないために

const int P_SIZE = 60;	//プレイヤーの半径
const int P_REBORN_X = 145;
const int P_REBORN_Y = 1937;
const double P_FULL_SPEED = 30;
const double P_HALF_SPEED = 15;
const int P_CLOCK = 20;//足音用みたいになってるがもっと使い道はありそう

/*--------主人--------*/
const int HUSBAND_RANGE = 60;
const int HUSBAND_FULL_SPEED = 35;
const int HUSBAND_HALF_SPEED = 20;
const int HUSBAND_SERCH_WIDTH = 440;
const int HUSBAND_SERCH_HEIGHT = 90;

/*--------夫人--------*/
const int MADAM_RANGE = 60;
const int MADAM_FULL_SPEED = 35;
const int MADAM_HALF_SPEED = 20;
const int MADAM_SERCH_WIDTH = 440;
const int MADAM_SERCH_HEIGHT = 90;

/*------１階の敵用静点-----*/
const int ENEPOSI_1[27 * 2] = {
	300,2200,//1
	300,3000,//2
	300,3500,//3
	1600,3500,//4
	1600,3000,//5
	1600,2205,//6
	1100,1300,//7
	1100,600,//8
	2100,650,//9
	2200,1300,//10
	2200,2250,//11
	2200,2650,//12
	3450,2650,//13
	3450,2050,//14
	3530,1300,//15
	2760,1300,//16
	2760,650,//17
	3530,650,//18
	4320,650,//19
	4320,1300,//20
	3900,2850,//21
	3900,1900,//22
	5100,1900,//23
	5100,2650,//24
	3900,2650,//25
	5100,3400,//26
	3900,3400//27
};
const int ENEPOSI_2[20 * 2] = {
	1100,2000,//1
	1100,440,//2
	1100,2550,//3
	330,2550,//4
	1560,2550,//5
	1873,2000,//6
	1873,1100,//7
	2750,2550,//8
	2750,2000,//9
	2750,1100,//10
	3600,1100,//11
	3600,2550,//12
	3600,3400,//13
	2800,3400,//14
	4800,3400,//15
	4350,2550,//16
	4350,1745,//17
	5100,1745,//18
	4350,430,//19
	330,3330,//20
};


/*--------長男--------*/
const int SON_RANGE = 60;
const double SON_FULL_SPEED = 35.0;
const double SON_HALF_SPEED = 20.0;
const int SON_SERCH_WIDTH = 1100;
const int SON_SERCH_HEIGHT = 150;


/*--------長女--------*/
const int DAUGHTER_RANGE = 60;
const int DAUGHTER_FULL_SPEED = 35;
const int DAUGHTER_HALF_SPEED = 20;
const int DAUGHTER_SERCH_WIDTH = 440;
const int DAUGHTER_SERCH_HEIGHT = 90;

const int HARD_COUNT = 5500;

/*---------鍵---------*/

const int KEYPOSI_1[9 * 2] = {
	109,1841,
	101,3593,
	1805,3593,
	1461,425,
	1669,417,
	3245,421,
	3937,429,
	3773,2833,
	3773,3585
};
const int KEYPOSI_2[7 * 2] = {
	1180,3600,
	2025,3590,
	5257,3597,
	1541,957,
	2473,921,
	3985,933,
	5377,1481
};
const int KEY_SIZE = 60;

/*-----------------------*/


const int UI_HEIGHT = 400;
const int UI_WIDTH = 300;
const int UI_MARGIN_HEIGHT = 20;
const int UI_MARGIN_WIDTH = 20;

//const int HPBAR_WIDTH = 900 * 0.75;
//const int HPBAR_HEIGHT = 150 * 0.75;
//const int HPBAR_MARGIN_HEIGHT = 130;
//const int HPBAR_MARGIN_WIDTH = 10 * 3;

//const int HPSQU_WIDTH = 610 * 0.75 + 10;
//const int HPSQU_HEIGHT = 50 * 0.75;
//const int HPSQU_MARGIN_WIDTH = 190 * 0.75;
//const int HPSQU_MARGIN_HEIGHT = 50 * 0.75 + 5;

#endif // !VALUE_H
