#include "Bullet.h"

Bullet::Bullet(float X, float Y): speed(0), time(0), life_time(0)
{
	float2 poss(X, Y);
	pos = poss;
}

Bullet::~Bullet() {}

Bullet::Bullet(float2 pos, float2  dir, float speed, float time, float life_time):pos(pos),dir(dir), speed(speed), time(time), life_time(life_time)
{
	float length = float2::getLength(pos, dir);
	cos_angle = (dir.getX() - pos.getX()) / length;
	sin_angle = (dir.getY() - pos.getY()) / length;
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

float2 Bullet::getCurrentPosition(float cur_time)
{
	float2 cur_position;
	cur_position.setX(pos.getX() + cur_time*speed*cos_angle);
	cur_position.setY(pos.getY() + cur_time*speed* sin_angle);

	return cur_position;
}

const float Bullet::getLifeTime()
{
	return life_time;
}

float2 Bullet::Richochet(Wall *wall, float2 bullet)
{
	float wall_length = float2::getLength(wall->getStart(), wall->getEnd());
	float left_length = float2::getLength(wall->getStart(), bullet);
	float right_length = float2::getLength(wall->getEnd(), bullet);
	//the angle between the the wall and the bullet
	float angle = (powf(wall_length, 2) - powf(left_length, 2) + powf(right_length, 2)) / (2 * wall_length*right_length);
	dir.setX(-(dir.getX()*cos(180 - angle) - dir.getY()*cos(180 - angle))); //new direction (the reflection of the angle)
	dir.setY(-(dir.getX()*cos(180 - angle) + dir.getY()*cos(180 - angle)));
	return dir;
}


float Bullet::getDirX()
{
	return dir.getX();
}

float Bullet::getDirY()
{
	return dir.getY();
}