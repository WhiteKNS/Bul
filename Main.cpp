#include <iostream>
#include <sstream>
#include <thread>
#include "BulletManager.h"
#include "Bullet.h"
#include "Wall.h"
#include "float2.h"
#include <vector>
#include <conio.h>
#include <Windows.h>

using namespace std;


int main()
{
	float2 point(30, 0);
	float2 point2(60, 80);
	float2 dir(1, 4);
	//Bullet *bullet = new Bullet(point);
	vector<Wall*>walls;
	vector<Bullet*>bullets;
	//bullets.push_back(new Bullet(point));
	walls.push_back(new Wall(new float2(0, 0), new float2(0,100)));
	walls.push_back(new Wall(new float2(0, 100), new float2(100, 100)));
	walls.push_back(new Wall(new float2(100, 100), new float2(100, 0)));
	walls.push_back(new Wall(new float2(100, 0), new float2(0, 0)));
/*
	if (_kbhit())
	{
		switch (_getch())
		{
		case '1': 
			
			bullets.push_back(new Bullet(point_shoot));
			break;
		default: break;
		}
	}
	*/
	BulletManager *manager = new BulletManager(walls);

	manager->Fire(point, dir, 1.0f, 0.1f, 6.0f);
	manager->Fire(point2, dir, 3.0f, 1.0f, 6.0f);
	//while(true)
	float time = 0.0f;
	while (true)
	{
		manager->Update(time++);
		Sleep(1000);
	}
	delete manager;
	/*
	for (unsigned int i = 0; i < walls.size(); ++i)
		for (unsigned int j = 0; j < bullets.size(); ++j)
		{
			{
				BulletManager::isIntersect(walls.at(i), bullets.at(j)->getBullet());
			}
		}
		*/
	return 0;
}



/*
void Function(int &a)
{
	ostringstream oss;
	oss << "Function 1 " << " We're in the Fucn 1 ";
	string str = oss.str();
	cout << str << endl;
	a++;
}

void Function2()
{
	cout << "Function 2 ";
	cout<<" In the Func 2 " << endl;
}

int main()
{
	
	int a = 4;
	thread th(Function, ref(a));
	thread th2(Function2);
	cout << a << " ";
	if (th2.joinable()) th2.join();
	if (th.joinable()) th.join();
	cout << a << " ";
	return 0;
}
*/

