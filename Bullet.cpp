#include "Bullet.h"

Bullet::Bullet(float X, float Y): speed(0), time(0), life_time(0)
{
	float2 poss(X, Y);
	pos = poss;
}

Bullet::~Bullet() {}

Bullet::Bullet(float2 pos, float2  dir, float speed, float time, float life_time):pos(pos),dir(dir), speed(speed), time(time), life_time(life_time)
{

}
Bullet::Bullet(float2 pos):pos(pos), speed(0), time(0), life_time(0)
{
}

float Bullet::getX()
{
	return pos.getX();
}

float Bullet::getY()
{
	return pos.getY();
}


void Bullet::SetBullet(float2 bullet)
{
	this->pos = bullet;
}

float2 Bullet::getBullet()
{
	return pos;
}