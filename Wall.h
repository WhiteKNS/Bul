#pragma once

#include "float2.h"

class Wall
{
	float2 *start_point;
	float2 *end_point;

public:

	Wall(float2 *start_point, float2 *end_point);
	~Wall();

	//float2 getStart();
	//float2 getEnd();
	float getStartX();
	float getStartY();
	float getEndX();
	float getEndY();
};