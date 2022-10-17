#pragma once

#include "Cell.h"
#include "Fortune.h"

using namespace std;

#define Cells std::vector<Cell*>

class VoronoiDiagram
{
public:
	VoronoiDiagram(Points& pPointList);
	void Run();
private:
	Cells cells;
	Fortune* fortune;
};