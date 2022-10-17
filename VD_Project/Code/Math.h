#pragma once

#include "Point.h"

class Math
{
public:
	static Point CrossPoint(Point a, Point b, Point c, Point d);
	static bool IsParallel(Point a, Point b, Point c, Point d);
};