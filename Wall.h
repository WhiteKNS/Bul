#pragma once

#include "float2.h"

class Wall
{
	float2 start_point;
	float2 end_point;

public:

	Wall(float2 start_point, float2 end_point);
	~Wall();

	const float2 getStart();
	const float2 getEnd();
	const float getStartX();
	const float getStartY();
	const float getEndX();
	const float getEndY();
};