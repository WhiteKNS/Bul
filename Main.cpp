#include <iostream>
#include <sstream>
#include <thread>
#include "BulletManager.h"
#include "Bullet.h"
#include "Wall.h"
#include "float2.h"
#include <vector>

using namespace std;


int main()
{
	float2 point(30, 0);
	Bullet *bullet = new Bullet(point);
	vector<Wall*>walls;
	walls.push_back(new Wall(new float2(0, 0), new float2(0,100)));
	walls.push_back(new Wall(new float2(0, 100), new float2(100, 100)));
	walls.push_back(new Wall(new float2(100, 100), new float2(100, 0)));
	walls.push_back(new Wall(new float2(100, 0), new float2(0, 0)));
	//Wall wall(pos1, pos2);


	for (unsigned int i = 0; i < walls.size(); ++i)
	BulletManager::isIntersect(walls.at(i), bullet->getBullet());

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

