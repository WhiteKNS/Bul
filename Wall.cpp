#include "Wall.h"


Wall::Wall(float2 *start_point, float2 *end_point):start_point(start_point), end_point(end_point) {
	
};

Wall::~Wall() {}


float2 Wall::getStart()
{
	return *start_point;
}

float2 Wall::getEnd()
{
	return *end_point;
}

float Wall::getStartX()
{
	return start_point->getX();
}

float Wall::getStartY()
{
	return start_point->getY();
}

float Wall::getEndX()
{
	return end_point->getX();
}

float Wall::getEndY()
{
	return end_point->getY();
}

