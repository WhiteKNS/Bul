#include "BulletManager.h"

BulletManager::BulletManager(vector<Wall*> walls) : walls(walls) {}

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
	for (unsigned int i = 0; i < walls.size(); ++i)
		for (unsigned int j = 0; j < bullets.size(); ++j)
		{
			{
				if (BulletManager::isIntersect(walls.at(i), bullets.at(j)->getBullet()))
				{
					cout << "bullet collision with the walls " << endl << "bullet with pos " << bullets.at(j)->getX() << " " << bullets.at(j)->getY() << " " << endl;
					cout << "walls with coords " << walls.at(i)->getStartX() << " " << walls.at(i)->getStartY() << " " << walls.at(i)->getEndX() << " " << walls.at(i)->getEndY() << endl;
				}
			}
		}
}

bool BulletManager::isIntersect(Wall *wall, float2 bullet)
{
	return (abs(sqrt(powf(wall->getStartX() - bullet.getX(), 2) + powf(wall->getStartY() - bullet.getY(), 2)) + sqrt(powf(wall->getEndX() - bullet.getX(), 2) + powf(wall->getEndY() - bullet.getY(), 2)) - sqrt(powf(wall->getEndX() - wall->getStartX(), 2) + powf(wall->getEndY() - wall->getStartY(), 2))) < 0.01);
}