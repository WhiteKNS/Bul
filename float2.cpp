#include "float2.h"

float2::float2(float X, float Y): X(X), Y(Y){}

float2::~float2() {}

float2::float2() {}

float float2::getX()
{
	return X;
}

float float2::getY()
{
	return Y;
}

float2& float2::operator+(const float2& rv)
{
	return float2(X + rv.X, Y + rv.Y);
}