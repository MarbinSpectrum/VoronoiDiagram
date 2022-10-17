#pragma once

#include "Cell.h"

class Arc
{
public:
	Arc(Cell* pCell);
	float GetY(float pX, float pSweepLine);
private:
	float x;
	float y;
	Cell* cell;

	//포물선 공식
	//y = ((x-ax)^2 + ay^2-line^2)/(2ay-2line)
};