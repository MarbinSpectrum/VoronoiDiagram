#pragma once

#include "fieldData.h"
#include <iostream>
#include <vector>
#include <queue>

class BeachLine
{
	
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