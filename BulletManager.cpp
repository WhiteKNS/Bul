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
					if (time < bullets.at(j)->getLifeTime())
					{
						if (isIntersect(walls.at(i), bullets.at(j)->getCurrentPosition(time)))
						{
							cout << "bullet collision with the walls " << endl << "bullet with pos " << bullets.at(j)->getX() << " " << bullets.at(j)->getY() << " " << endl;
							cout << "walls with coords " << walls.at(i)->getStartX() << " " << walls.at(i)->getStartY() << " " << walls.at(i)->getEndX() << " " << walls.at(i)->getEndY() << endl;
						}
						if (NearTheWall((walls.at(i)), bullets.at(j)->getCurrentPosition(time)))
						{
							cout << "Near the wall" << endl;
							bullets.at(j)->Richochet(walls.at(i), bullets.at(j)->getBullet());
							cout << "ricosheted to pos" <<bullets.at(j)->getDirX()<<" "<< bullets.at(j)->getDirY()<< endl;
							bullets.erase(bullets.begin() + j);
							vector<Bullet*>(bullets).swap(bullets);
							cout << "deleted" << endl;
						}
					}
				}
			}
}

bool BulletManager::isIntersect(Wall *wall, float2 bullet)
{
	return (abs(sqrt(powf(wall->getStartX() - bullet.getX(), 2) + powf(wall->getStartY() - bullet.getY(), 2)) + sqrt(powf(wall->getEndX() - bullet.getX(), 2) + powf(wall->getEndY() - bullet.getY(), 2)) - sqrt(powf(wall->getEndX() - wall->getStartX(), 2) + powf(wall->getEndY() - wall->getStartY(), 2))) < 0.01);
}

bool BulletManager::NearTheWall(Wall *wall, float2 bullet)
{
	float wall_length = float2::getLength(wall->getStart(), wall->getEnd());
	float left_length = float2::getLength(wall->getStart(), bullet);
	float right_length = float2::getLength(wall->getEnd(), bullet);

	float total_length = (wall_length + right_length + left_length)/2;
	//the highth of the triangle from the bullet to the wall is the nearest distant to the wall

	return 2 * sqrt(total_length*(total_length - wall_length)*(total_length - left_length)*(total_length - right_length)) / wall_length <= COLLISION;
}





