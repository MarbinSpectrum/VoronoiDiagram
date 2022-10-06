#include "VoronoiDiagram.h"

void VoronoiDiagram::Run()
{
	std::priority_queue<Event> events;

	while (events.empty() == false)
	{
		Event nowEvent = events.top();
		events.pop();

		switch (nowEvent.type)
		{
			case Event::EventType::site_event:
			{

			}
			break;
			case Event::EventType::vertex:
			{

			}
			break;
		}
	}
}
