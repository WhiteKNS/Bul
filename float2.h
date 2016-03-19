#pragma once


class float2
{
	float X;
	float Y;

public:

	float2();
	float2(float X, float Y);
	~float2();
	float2& operator+(const float2& rv);

	float getX();
	float getY();
};