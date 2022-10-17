#include "Cell.h"

Cell::Cell(Point pPoint)
: x(pPoint.x)
, y(pPoint.y)
{
}

Cell::Cell(float pX, float pY)
: Cell(Point(pX,pY))
{
}

void Cell::AddVerTex(Point pPoint)
{
	vertex.emplace_back(pPoint);
}
