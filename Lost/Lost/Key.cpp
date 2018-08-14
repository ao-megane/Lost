#include"Key.h"
#include"Chore.h"
#include"Value.h"

Circle key;
int keyfloor;
int keyImage;

int KeyInitialize() {
	keyImage = LoadGraph("images/key/1.png");
	key.Set(0, 0, KEY_SIZE, 0);
	return 0;
}

int SetKeyPosi() {
	if (GetRand() % 2) {
		keyfloor = 1;
		switch (GetRand() % 9)
		{
		case 0:
			key.Set(KEYPOSI_1[0], KEYPOSI_1[1], KEY_SIZE, 0);
			break;
		case 1:
			key.Set(KEYPOSI_1[2], KEYPOSI_1[3], KEY_SIZE, 0);
			break;
		case 2:
			key.Set(KEYPOSI_1[4], KEYPOSI_1[5], KEY_SIZE, 0);
			break;
		case 3:
			key.Set(KEYPOSI_1[6], KEYPOSI_1[7], KEY_SIZE, 0);
			break;
		case 4:
			key.Set(KEYPOSI_1[8], KEYPOSI_1[9], KEY_SIZE, 0);
			break;
		case 5:
			key.Set(KEYPOSI_1[10], KEYPOSI_1[11], KEY_SIZE, 0);
			break;
		case 6:
			key.Set(KEYPOSI_1[12], KEYPOSI_1[13], KEY_SIZE, 0);
			break;
		case 7:
			key.Set(KEYPOSI_1[14], KEYPOSI_1[15], KEY_SIZE, 0);
			break;
		case 8:
			key.Set(KEYPOSI_1[16], KEYPOSI_1[17], KEY_SIZE, 0);
			break;
		default:
			break;
		}
	}
	else {
		keyfloor = 2;
		switch (GetRand() % 7)
		{
		case 0:
			key.Set(KEYPOSI_2[0], KEYPOSI_2[1], KEY_SIZE, 0);
			break;
		case 1:
			key.Set(KEYPOSI_2[2], KEYPOSI_2[3], KEY_SIZE, 0);
			break;
		case 2:
			key.Set(KEYPOSI_2[4], KEYPOSI_2[5], KEY_SIZE, 0);
			break;
		case 3:
			key.Set(KEYPOSI_2[6], KEYPOSI_2[7], KEY_SIZE, 0);
			break;
		case 4:
			key.Set(KEYPOSI_2[8], KEYPOSI_2[9], KEY_SIZE, 0);
			break;
		case 5:
			key.Set(KEYPOSI_2[10], KEYPOSI_2[11], KEY_SIZE, 0);
			break;
		case 6:
			key.Set(KEYPOSI_2[12], KEYPOSI_2[13], KEY_SIZE, 0);
			break;
		default:
			break;
		}
	}
	return 0;
}

int GetKeyFloor() {
	return keyfloor;
}

Circle GetKeyPosi() {
	return key;
}

int KeyDraw(Dot player,int floor) {
	if (floor == 1) {
		if (keyfloor == 1) {
			DrawModiGraph(
				key.Getx() - key.GetRadius() + DISP_WIDTH / 2.0 - player.Getx(), key.Gety() - key.GetRadius() + DISP_HEIGHT / 2.0 - player.Gety(),
				key.Getx() + key.GetRadius() + DISP_WIDTH / 2.0 - player.Getx(), key.Gety() - key.GetRadius() + DISP_HEIGHT / 2.0 - player.Gety(),
				key.Getx() + key.GetRadius() + DISP_WIDTH / 2.0 - player.Getx(), key.Gety() + key.GetRadius() + DISP_HEIGHT / 2.0 - player.Gety(),
				key.Getx() - key.GetRadius() + DISP_WIDTH / 2.0 - player.Getx(), key.Gety() + key.GetRadius() + DISP_HEIGHT / 2.0 - player.Gety(),
				keyImage, 1);
			DrawCircle(key.Getx() - player.Getx(), key.Gety() - player.Gety(), key.GetRadius(), RED, 1, 0);
		}
	}
	else if (floor == 4) {
		if (keyfloor == 2) {
			DrawModiGraph(
				key.Getx() - key.GetRadius() + DISP_WIDTH / 2.0 - player.Getx(), key.Gety() - key.GetRadius() + DISP_HEIGHT / 2.0 - player.Gety(),
				key.Getx() + key.GetRadius() + DISP_WIDTH / 2.0 - player.Getx(), key.Gety() - key.GetRadius() + DISP_HEIGHT / 2.0 - player.Gety(),
				key.Getx() + key.GetRadius() + DISP_WIDTH / 2.0 - player.Getx(), key.Gety() + key.GetRadius() + DISP_HEIGHT / 2.0 - player.Gety(),
				key.Getx() - key.GetRadius() + DISP_WIDTH / 2.0 - player.Getx(), key.Gety() + key.GetRadius() + DISP_HEIGHT / 2.0 - player.Gety(),
				keyImage, 1);
			DrawCircle(key.Getx() - player.Getx(), key.Gety() - player.Gety(), key.GetRadius(), RED, 1, 0);
		}
	}

	DrawFormatString(200, 20, RED, "floor:%d,x:%d,y:%d", keyfloor, key.Getx(), key.Gety());

	return 0;
}