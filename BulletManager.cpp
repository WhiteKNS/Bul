#include "BulletManager.h"
#include <mutex>
#include <Windows.h>

mutex g_lock;

BulletManager::BulletManager(list <Wall*> walls) : walls(walls) {}

BulletManager::~BulletManager() 
{
	
	for (vector <Bullet*> ::iterator iter = bullets.begin(); iter != bullets.end(); ++iter)
	{
		delete *iter;
	}
	for (list <Wall*> ::iterator iter = walls.begin(); iter != walls.end(); ++iter)
	{
		delete *iter;
	}
}

void BulletManager::Fire(float2 pos, float2 dir, float speed, float time, float life_time)
{
	g_lock.lock();
	//cout << "speed" << speed << " time " << time << " life time" << life_time << endl;
	bullets.push_back(new Bullet(pos, dir, speed, time, life_time));
	//cout << "entered thread " << this_thread::get_id() << endl;
	//this_thread::sleep_for(chrono::seconds(rand() % 10));
	//cout << "leaving thread " << this_thread::get_id() << endl;
	g_lock.unlock();
}

void BulletManager::Update(float time)
{
	Over = false;
	g_lock.lock();

	if (!bullets.empty() && !walls.empty())
	{
		for (list<Wall*>::iterator i = walls.begin(); i != walls.end(); i++)
		{
			for (unsigned int j = 0; j < bullets.size(); ++j)
			{
				{
					//cout << walls.size() << " " << bullets.size() << " i " << i << " j " << j << endl;
					if (time < bullets.at(j)->getLifeTime())
					{
						
						if (NearTheWall((*i), bullets.at(j)->getCurrentPosition(time)))

						{
							
							cout << "Near the wall" << endl;
							bullets.at(j)->Richochet(*i, bullets.at(j)->getBullet());

							vector <Bullet*> ::iterator iter;
							iter = bullets.begin() + j;
							delete *iter;
							cout << "ricosheted to pos" << bullets.at(j)->getDirX() << " " << bullets.at(j)->getDirY() << endl;
							bullets.erase(bullets.begin() + j);
							vector<Bullet*>(bullets).swap(bullets);
							delete * i;
							walls.erase(i);
							list<Wall*>(walls).swap(walls);
							//i = 0;
							i = walls.begin();
							 j = 0;
							Sleep(3000);
						}
					}
					else
					{
						vector <Bullet*> ::iterator iter;
						iter = bullets.begin() + j;
						delete *iter;
						bullets.erase(bullets.begin() + j);
						vector<Bullet*>(bullets).swap(bullets);
						cout << "life_end" << endl;
					}
				}
			}
		
		}
	}
	else
	{
		Over = true;
		cout << "no bullets " << endl;
	}
	g_lock.unlock();
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





