#include "Math.h"

Point Math::CrossPoint(Point a, Point b, Point c, Point d)
{
	float x = ((a.x * b.y - a.y * b.x) * (c.x - d.x) - (a.x - b.x) * (c.x * d.y - c.y * d.x))
		/ ((a.x - b.x) * (c.y - d.y) - (a.y - b.y) * (c.x - d.x));
	float y = ((a.x * b.y - a.y * b.x) * (c.y - d.y) - (a.y - b.y) * (c.x * d.y - c.y * d.x))
		/ ((a.x - b.x) * (c.y - d.y) - (a.y - b.y) * (c.x - d.x));
	return Point(x,y);
}

bool Math::IsParallel(Point a, Point b, Point c, Point d)
{
	if (a.x == b.x && c.x == d.x)
	{
		//두 직선 모두 y축에 평행하다.
		return true;
	}
	if (a.y == b.y && c.y == d.y)
	{
		//두 직선 모두 x축에 평행하다.
		return true;
	}
	float am = (b.y - a.y) / (b.x - a.x);
	float bm = (d.y - c.y) / (d.x - c.x);
	if (am == bm)
	{
		//두 직선의 기울기가 같다.
		return true;
	}
	return false;
}
