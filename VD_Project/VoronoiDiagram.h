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
	Event(float pSweepY, Site* pSite) //���ο� site�� ���������� ����Ǵ� ������
	: sweepY(pSweepY)
	, type(EventType::site_event)
	, nowSite(pSite)
	, prvSite(NULL)
	, nxtSite(NULL)
	{
	}

	float sweepY; //�������߿� �̺�Ʈ�� �߻��� Y��
	enum class EventType
	{
		site_event = 0, //���ο� site�� ���� �������� �����ȴ�.
		vertex_event = 1 //��輱�� �����ǰ� �������� �����ȴ�.
	} type; //�߻��� �̺�Ʈ ����

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