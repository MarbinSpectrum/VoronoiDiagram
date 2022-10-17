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
		//�� ���� ��� y�࿡ �����ϴ�.
		return true;
	}
	if (a.y == b.y && c.y == d.y)
	{
		//�� ���� ��� x�࿡ �����ϴ�.
		return true;
	}
	float am = (b.y - a.y) / (b.x - a.x);
	float bm = (d.y - c.y) / (d.x - c.x);
	if (am == bm)
	{
		//�� ������ ���Ⱑ ����.
		return true;
	}
	return false;
}
