#include "Arc.h"

Arc::Arc(Cell* pCell)
: cell(pCell)
, x(pCell->x)
, y(pCell->y)
{
}

float Arc::GetY(float pX,float pSweepLine)
{
	float res = ((pX - x) * (pX - x) + y * y - pSweepLine * pSweepLine) 
		/ (2 * y - 2 * pSweepLine);
	return res;
}
