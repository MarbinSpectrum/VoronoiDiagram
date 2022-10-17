#pragma once

#include "BeachLine.h"
#include "Cell.h"
#include "Arc.h"

#include <set>

class BeachLine
{
	multiset<Arc*, greater<>> line;

public:
	void AddArc(Cell* pCell);
};