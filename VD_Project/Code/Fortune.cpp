#include "Fortune.h"

Fortune::Fortune(Cells pCells)
{
	for (int i = 0; i < pCells.size(); i++)
	{
		Cell* cell = pCells[i];
		AddSite(cell);
	}
}

void Fortune::Run()
{
	while (eventQueue.empty() == false)
	{
		Event nowEvent = eventQueue.top();
		eventQueue.pop();

		if (nowEvent.eventType == Event::EventType::Point)
			PointEvent(nowEvent);
		else if (nowEvent.eventType == Event::EventType::Vertex)
			VertexEvent(nowEvent);
	}
}

void Fortune::AddSite(Cell* pCell)
{
	eventQueue.push(Event(pCell));
}

void Fortune::PointEvent(Event pEvent)
{
}

void Fortune::VertexEvent(Event pEvent)
{
}
