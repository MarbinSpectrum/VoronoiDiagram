#pragma once

#include "Point.h"
#include "Event.h"
#include "Cell.h"

#include <queue>

using namespace std;

#define Cells std::vector<Cell*>
#define EventQueue std::priority_queue<Event>

class Fortune
{
public:
	Fortune(Cells pCells);
	void Run();
private:
	EventQueue eventQueue;

private:
	void AddSite(Cell* pCell);
	void PointEvent(Event pEvent);
	void VertexEvent(Event pEvent);
};