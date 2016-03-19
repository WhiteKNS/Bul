#pragma once

#include <cmath>

class float2
{
	float X;
	float Y;

public:

	float2();
	float2(float X, float Y);
	~float2();
	float2 operator+(const float2& rv);

	float getX();
	float getY();

	void setX(float X);
	void setY(float Y);

	static const float getLength(float2 first_point, float2 second_point);
};