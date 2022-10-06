#pragma once

#include "fieldData.h"
#include <iostream>
#include <vector>
#include <queue>

struct Arc
{

};

class BeachLine
{

};

struct Event
{
	Event(float pSweepY, Site* pSite) //새로운 site에 접속했을때 실행되는 생성자
	: sweepY(pSweepY)
	, type(EventType::site_event)
	, nowSite(pSite)
	, prvSite(NULL)
	, nxtSite(NULL)
	{
	}

	float sweepY; //스위핑중에 이벤트가 발생한 Y값
	enum class EventType
	{
		site_event = 0, //새로운 site에 접촉 포물선이 생성된다.
		vertex_event = 1 //경계선이 교차되고 포물선이 삭제된다.
	} type; //발생한 이벤트 종류

	Site* nowSite;
	Site* prvSite;
	Site* nxtSite;
	
	bool operator>(const Event& l)const { return sweepY > l.sweepY; }
};

struct Arc
{
	enum
};
class VoronoiDiagram
{
public:
	void Run();
private:
	std::vector<Site> mSites;
	std::vector<Face> mFaces;
	std::vector<Vertex> mVertices;
	std::vector<HalfEdge> mHalfEdges;
};