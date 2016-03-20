#include "float2.h"

float2::float2(float X, float Y): X(X), Y(Y){}

float2::~float2() {}

float2::float2():X(0),Y(0) {}

float float2::getX()
{
	return X;
}

float float2::getY()
{
	return Y;
}

float2 float2::operator+(const float2& cord)
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

const float float2::getLength(float2 first_point, float2 second_point)
{
	return hypot(first_point.getX() - second_point.getX(), first_point.getY() - second_point.getY());
	//return sqrt(powf(first_point.getX() - second_point.getX(), 2) + powf(first_point.getY() - second_point.getY(), 2));
}