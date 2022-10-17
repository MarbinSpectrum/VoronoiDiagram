#include "VoronoiDiagram.h"
#include <algorithm>

VoronoiDiagram::VoronoiDiagram(Points& pPointList)
{
	sort(pPointList.begin(), pPointList.end(),
		[](Point a, Point b) -> bool
		{
			if (a.y == b.y)
				return a.x < b.x;
			return a.y > b.y;
		});

	for (int i = 0; i < pPointList.size(); i++)
	{
		Cell* cell = new Cell(pPointList[i]);
		cells.push_back(cell);
	}
	fortune = new Fortune(cells);
}

void VoronoiDiagram::Run()
{
	fortune->Run();
}