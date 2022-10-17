#pragma once

#include "Point.h"

#include <vector>

using namespace std;

#define Points std::vector<Point>

class Cell
{
public:
	Cell(Point pPoint);
	Cell(float pX, float pY);

public:
	float x;
	float y;
private:
	Points vertex;
public:
	void AddVerTex(Point pPoint);
};