#pragma once


#include "Bullet.h"
#include "float2.h"
#include "Wall.h"
#include <vector>
#include <list>
#include <iostream>
#include <cmath>

#define COLLISION 0.1

using namespace std;

class BulletManager
{
	list<Wall*> walls;
	vector <Bullet*> bullets;

	bool isIntersect(Wall *wall, float2 bullet);
	bool NearTheWall(Wall *wall, float2 bullet);
	bool NotPlane(Wall *wall, Bullet *bullet, float time);

public:

	bool Over;

	BulletManager(list <Wall*> walls);
	~BulletManager();

	void Update(float time);
	void Fire(float2 pos, float2 dir, float speed, float time, float life_time);
};