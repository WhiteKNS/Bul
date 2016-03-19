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

float2& float2::operator+(const float2& cord)
{
	return float2(X + cord.X, Y + cord.Y);
}

void float2::setX(float X)
{
	this->X = X;
}

void float2::setY(float Y)
{
	this->Y = Y;
}