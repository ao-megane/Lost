#include"Sound.h"

int Sound::Initialize() {
	Set(0, 0, 0, 0, 0);
	return 0;
}
int Sound::Set(int x, int y, double Speed,double LifeSpan, int count) {
	center.Setx(x);
	center.Sety(y);
	speed = Speed;
	lifeSpan = LifeSpan;
	keepCount = count;
	return 0;
}
int Sound::Set(Dot a, double b, double d,int c) {
	center = a;
	speed = c;
	lifeSpan = d;
	keepCount = c;
	return 0;
}
bool Sound::isHitDot(Dot a,int count) {
	if ((count - keepCount) < lifeSpan) {
		if ((center.Getx() - a.Getx())*(center.Getx() - a.Getx()) + (center.Gety() - a.Gety())* (center.Gety() - a.Gety()) <= (count - keepCount) * SOUND_SPEED) {
			return true;
		}
		else {
			return false;
		}
	}
	else{
		return false;
	}
	
}
Dot Sound::GetDot() {
	return center;
}
int Sound::Getx() {
	return center.Getx();
}
int Sound::Gety() {
	return center.Gety();
}
double Sound::GetRadius(int count) {
	if ((count - keepCount) < lifeSpan)
		return (count - keepCount) * SOUND_SPEED;
	else
		return 0;
}
int Sound::GetLifeSpan() {
	return lifeSpan;
}
int Sound::GetKeepCount() {
	return keepCount;
}
Dot decoi_sound;
int Sound::Draw(Circle player,int count,int handle,int flag) {//0 両耳　1　右耳のみ　2　左耳のみ 3 両耳ない
	if (flag == 0) {
		DrawCircle(
			center.Getx() + DISP_WIDTH / 2.0 - player.Getx(), center.Gety() + DISP_HEIGHT / 2.0 - player.Gety(),
			(count - keepCount) * SOUND_SPEED, handle, 0
		);
	}
	else if (flag == 2) {//右耳のみ
		//for (double i = 0.0; i < 2 * PI; i += PI / 180.0) {
		//	decoi_sound[0].Setx(center.Getx() + (count - keepCount) * SOUND_SPEED * cos(i) - player.Getx()/* - MASK_WIDTH / 2.0*/);
		//	decoi_sound[0].Sety(center.Gety() + (count - keepCount) * SOUND_SPEED * -sin(i) - player.Gety()/* - MASK_WIDTH / 2.0*/);
		//	decoi_sound[0] = RotateDot(-player.GetDir(), decoi_sound[0]);
		//	if (decoi_sound[0].Gety() > 0)
		//		return 0;
		//	else {
		//		DrawPixel(
		//			center.Getx() + (count - keepCount) * SOUND_SPEED * cos(i) - player.Getx() + DISP_WIDTH / 2.0,
		//			center.Gety() + (count - keepCount) * SOUND_SPEED * -sin(i) - player.Gety() + DISP_HEIGHT / 2.0,
		//			handle);
		//	}
		//	DrawPixel(
		//		center.Getx() + (count - keepCount) * SOUND_SPEED * cos(i) - player.Getx() + DISP_WIDTH / 2.0,
		//		center.Gety() + (count - keepCount) * SOUND_SPEED * -sin(i) - player.Gety() + DISP_HEIGHT / 2.0,
		//		handle);
		//	printfDx("DRAW!!\n");
		//}
		decoi_sound.Set(center.Getx() - player.Getx(), center.Gety() - player.Gety());
		decoi_sound = RotateDot(-player.GetDir(), decoi_sound);
		if(decoi_sound.Gety() > 0 && decoi_sound.Getx() > 0)
			DrawCircle(
				center.Getx() + DISP_WIDTH / 2.0 - player.Getx(), center.Gety() + DISP_HEIGHT / 2.0 - player.Gety(),
				(count - keepCount) * SOUND_SPEED, handle, 0
			);
	}
	else if (flag == 1) {
		decoi_sound.Set(center.Getx() - player.Getx(), center.Gety() - player.Gety());
		decoi_sound = RotateDot(-player.GetDir(), decoi_sound);
		if (decoi_sound.Gety() < 0 && decoi_sound.Getx() > 0)
			DrawCircle(
				center.Getx() + DISP_WIDTH / 2.0 - player.Getx(), center.Gety() + DISP_HEIGHT / 2.0 - player.Gety(),
				(count - keepCount) * SOUND_SPEED, handle, 0
			);
	}
	else if (flag == 3) {
		;
	}
	return 0;
}

int SoundMng::Initialzie() {
	for (int i = 0; i < 20; i++) {
		sound[i].Initialize();
	}
	return 0;
}
int SoundMng::Born(Dot dot, double speed, double lifeSpan, int count) {
	for (int i = 0; i < 20; i++) {
		if ((count - sound[i].GetKeepCount()) > sound[i].GetLifeSpan()) {
			sound[i].Set(dot, speed, lifeSpan, count);
			//printfDx("BORN!!\n");
			break;
		}
	}
	return 0;
}
int SoundMng::Draw(Circle player,int count,int handle,int flag) {
	for (int i = 0; i < 20; i++) {
		if ((count - sound[i].GetKeepCount()) < sound[i].GetLifeSpan()) {
			sound[i].Draw(player, count, handle,flag);
			//printfDx("DRAW!!:\n");
		}
		else {
			;
		}
	}
	return 0;
}
bool SoundMng::isHitDot(Dot a, int count) {
	for (int i = 0; i < 20; i++) {
		if (sound[i].isHitDot(a,count)) {
			return true;
		}
	}
	return 0;
}