#pragma once


#include "Bullet.h"
#include "float2.h"
#include "Wall.h"
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class BulletManager
{
	vector <Wall*> walls;
	vector <Bullet*> bullets;



public:

	BulletManager(vector <Wall*> walls);
	~BulletManager();

	static bool isIntersect(Wall *wall, float2 bullet);
	void Update(float time);
	void Fire(float2 pos, float2 dir, float speed, float time, float life_time);
};