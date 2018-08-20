#include"Sound.h"

int Sound::Set(int a, int b, double c,int d, int count) {
	center.Setx(a);
	center.Sety(b);
	speed = c;
	lifeSpan = d;
	keepCount = count;
	return 0;
}
int Sound::Set(Dot a, double b, int d,int c) {
	center = a;
	speed = c;
	lifeSpan = d;
	keepCount = c;
	return 0;
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
		return count - keepCount;
	else
		return 0;
}
int Sound::Draw(Dot player,int count,int handle) {
	if ((count - keepCount) * SOUND_SPEED < lifeSpan)
		DrawCircle(center.Getx() + DISP_WIDTH / 2.0 - player.Getx(), center.Gety() + DISP_HEIGHT / 2.0 - player.Gety(), (count - keepCount)*SOUND_SPEED, handle, 0);
	else {
		;
	}
	return 0;
}

int SoundMng::Initialzie() {
	num = 0;
	return 0;
}
int SoundMng::Born(Dot dot, int speed, int lifeSpan, int count) {

}