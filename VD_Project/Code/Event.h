#pragma once

#include "Cell.h"

struct Event
{
	enum class EventType
	{
		Point,
		Vertex
	};
	EventType eventType;
	float x;
	float y;
	Cell* cell;
	Event(float pX, float pY)
	: eventType(EventType::Vertex)
	, x(pX)
	, y(pY)
	, cell(NULL)
	{
	}
	Event(Cell* pCell)
	: eventType(EventType::Point)
	, x(pCell->x)
	, y(pCell->y)
	, cell(pCell)
	{
	}
	bool operator<(const Event& e) const
	{
		return y > e.y;
	}
};