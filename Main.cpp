#include <iostream>
#include <sstream>
#include <thread>
#include "BulletManager.h"
#include "Bullet.h"
#include "Wall.h"
#include "float2.h"
#include <vector>
#include <list>
#include <ctime>
#include <Windows.h>

using namespace std;

void FuncThread(BulletManager &man, float2 &pos, float2 &dir, float speed, float time, float life_time )
{
	man.Fire(pos, dir, speed, time, life_time);
}

void Randomization(float &speed, float &time, float &life_time)
{
		speed = (10.0f * rand()) / RAND_MAX,
		time = (5.0f * rand()) / RAND_MAX,
		life_time = (20.0f * rand()) / RAND_MAX+ 10.0f;
}

int main()
{
	srand((unsigned)time(NULL));
	
	list<Wall*>walls;

	for (unsigned int i = 0; i < 20; ++i)
	{
		float2 pos_first(100.0f * rand() / RAND_MAX, 100.0f * rand() / RAND_MAX);
		float2 pos_second(100.0f * rand() / RAND_MAX, 100.0f * rand() / RAND_MAX);
		walls.push_back(new Wall(pos_first, pos_second));
	}

	vector<thread> threads;

	BulletManager manager(walls); 

	for (unsigned int i = 0; i < 25; ++i)
	{
		
		float2 point((100.0f * rand()) / RAND_MAX, (100.0f * rand()) / RAND_MAX);
		float2 dir((3.0f * rand()) / RAND_MAX, (4.0f * rand()) / RAND_MAX);
		float speed, time, life_time;
		Randomization(speed, time, life_time);
		threads.push_back(thread(FuncThread, ref(manager), ref(point), ref(dir), ref(speed), ref(time), ref(life_time)));
	}
	

	for (auto& th : threads)
	{
		if (th.joinable()) th.join();
	}

	float timer = 1.0f;

	while (true)
	{
		manager.Update(timer++);

		Sleep(1000);
		if (manager.Over) break;
	}

	
	walls.clear();

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

