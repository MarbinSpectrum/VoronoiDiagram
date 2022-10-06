#pragma once

#include <iostream>

struct Site;
struct Vertex;
struct Face;
struct HalfEdge;

struct Site
{
	//Site의 번호
	std::size_t index;
};

struct Vertex
{
	//점의 x,y 좌표
	float x, y;
};

struct Face
{
	//VoronoiDiagram으로 분할된 면

	Site* site; //해당 면의 Site
	HalfEdge* outerComponet; //면에 해당하는 경계선
};

struct HalfEdge
{
	//경계선객체

	Vertex* origin; //시작점
	Vertex* destination; //끝점

	//경계선은 두개의 Face가 만나서 생기는 것이다.
	//해당 Face가 아닌 다른 Face에 속한 똑같은 크기의 HalfEdge도 존재한다는 뜻이다.
	//twin은 그것을 의미한다.
	HalfEdge* twin;

	Face* incidentFace; //해당 경계선이 속한 Face
	HalfEdge* prev; //Face를 구성하는 HalfEdge의 이전순서 HalfEdge
	HalfEdge* next; //Face를 구성하는 HalfEdge의 다음순서 HalfEdge
};