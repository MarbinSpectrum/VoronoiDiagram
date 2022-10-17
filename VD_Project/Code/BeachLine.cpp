#include "BeachLine.h"

void BeachLine::AddArc(Cell* pCell)
{
	Arc* arc = new Arc(pCell);
	line.insert(arc);
}
