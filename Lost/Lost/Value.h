#ifndef VALUE_H
#define VALUE_H
#include"dxlib.h"

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

const int MAP_WIDTH = 10800 * 0.5;
const int MAP_HEIGHT = 7200 * 0.5;

const int MASK_WIDTH = 2600;

//const int DOOR = GetColor(0, 255, 0);
const int DOOR = GetColor(255, 0, 0);
const int WALL = GetColor(0, 0, 0);
const int STEP1 = GetColor(255, 0, 0);
const int STEP2 = GetColor(0, 0, 255);
const int FLOOR1 = GetColor(0, 0, 255);
const int FLOOR2 = GetColor(0, 0, 255);

const double JUDGE_MARGIN = 1.0;	//プレイヤーと壁の追突について，埋め込まれないために

const int P_SIZE = 60;	//プレイヤーの半径
const int P_REBORN_X = 250;
const int P_REBORN_Y = 1000;
const double P_FULL_SPEED = 30;
const double P_HALF_SPEED = 15;
const int P_CLOCK = 20;//足音用みたいになってるがもっと使い道はありそう
//↑判定系 ↓描画系
const double P_WIDTH = 1 * P_SIZE;
const double P_HEIGHT = 1 * P_SIZE;

const int HUSBAND_RANGE = 300;	//主人の大きさ
//↑判定系 ↓描画系
const double HUSBAND_WIDTH = 1 * HUSBAND_RANGE;
const double HUSBAND_HEIGHT = 1 * HUSBAND_RANGE;

const int MADAM_RANGE = 200;	//夫人の大きさ
//↑判定系 ↓描画系
const double MADAM_WIDTH = 1 * MADAM_RANGE;
const double MADAM_HEIGHT = 1 * MADAM_RANGE;

const int SON_RANGE = 200;	//長男
//↑判定系 ↓描画系
const double SON_WIDTH = 1 * SON_RANGE;
const double SON_HEIGHT = 1 * SON_RANGE;

const int DAUGHTER_RANGE = 300;	//長女
//↑判定系 ↓描画系HU
const double DAUGHTER_WIDTH = 1 * DAUGHTER_RANGE;
const double DAUGHTER_HEIGHT = 1 * DAUGHTER_RANGE;

const int NORMAL_COUNT = 5500;
const int HARD_COUNT = 5500;

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
