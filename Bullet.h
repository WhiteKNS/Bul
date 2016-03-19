#pragma once
#include "float2.h"

class Bullet
{
	float2 pos;
	float2 dir;
	float speed;
	float time;
	float life_time;


public:

	Bullet(float2 pos);
	Bullet(float X, float Y);
	Bullet(float2 pos, float2  dir,float speed,float time, float life_time);
	~Bullet();

	float getX();
	float getY();

	void SetBullet(float2 bullet);
	float2 getBullet();

};