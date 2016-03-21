#pragma once
#include "float2.h"
#include <iostream>
#include "Wall.h"

using namespace std;

class Bullet
{
	float2 pos;
	float2 dir;
	float speed;
	float time;
	float life_time;

	float cos_angle;
	float sin_angle;


public:

	Bullet(float2 pos);
	Bullet(float X, float Y);
	Bullet(float2 pos, float2  dir, float speed, float time, float life_time);
	~Bullet();

	float getX();
	float getY();

	void SetBullet(float2 bullet);
	const float2 getBullet();
	float2 getCurrentPosition(float cur_time);
	float2 Richochet(Wall *wall, float2 bullet);
	const float2 getDir();

	const float getLifeTime();
};