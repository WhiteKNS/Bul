#include "BulletManager.h"

BulletManager::BulletManager(vector<Wall> walls) : walls(walls) {}

BulletManager::~BulletManager() 
{
	bullets.clear();
}

void BulletManager::Fire(float2 pos, float2 dir, float speed, float time, float life_time)
{
	bullets.push_back(new Bullet(pos, dir, speed, time, life_time));
}

void BulletManager::Update(float time)
{
	
}

bool BulletManager::isIntersect(Wall *wall, float2 bullet)
{
	if (abs(sqrt(powf(wall->getStartX() - bullet.getX(), 2) + powf(wall->getStartY() - bullet.getY(), 2)) + sqrt(powf(wall->getEndX() - bullet.getX(), 2) + powf(wall->getEndY() - bullet.getY(), 2)) - sqrt(powf(wall->getEndX() - wall->getStartX(), 2) + powf(wall->getEndY() - wall->getStartY(), 2))) < 0.01)
	{
		cout << "bullet collision with the walls " << endl << "bullet with pos " <<bullet.getX()<<" "<<bullet.getY()<<" "<< endl;
		cout << "walls with coords " << wall->getStartX() << " " << wall->getStartY() << " " << wall->getEndX() << " " << wall->getEndY() << endl;
		return true;
	}
	else
	{
		cout << "bullet continue to fly" << endl;
		return false;
	}
}