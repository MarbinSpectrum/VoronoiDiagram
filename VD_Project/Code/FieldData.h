#pragma once

#include <iostream>

struct Site;
struct Vertex;
struct Face;
struct HalfEdge;
struct Arc;

struct Site
{
	//Site�� ��ȣ
	std::size_t index;
};

struct Vertex
{
	//���� x,y ��ǥ
	float x, y;
};

struct Face
{
	//VoronoiDiagram���� ���ҵ� ��

	Site* site; //�ش� ���� Site
	HalfEdge* outerComponet; //�鿡 �ش��ϴ� ��輱
};

struct HalfEdge
{
	//��輱��ü

	Vertex* origin; //������
	Vertex* destination; //����

	//��輱�� �ΰ��� Face�� ������ ����� ���̴�.
	//�ش� Face�� �ƴ� �ٸ� Face�� ���� �Ȱ��� ũ���� HalfEdge�� �����Ѵٴ� ���̴�.
	//twin�� �װ��� �ǹ��Ѵ�.
	HalfEdge* twin;

	Face* incidentFace; //�ش� ��輱�� ���� Face
	HalfEdge* prev; //Face�� �����ϴ� HalfEdge�� �������� HalfEdge
	HalfEdge* next; //Face�� �����ϴ� HalfEdge�� �������� HalfEdge
};

struct Arc
{
	//ȣ�� ���� ��Ʈ���� ������ �����̴�.
	enum class Color
	{
		//����� ���� �ǹ��Ѵ�.
		RED,
		BLACK
	} color;
	Arc* parent;
	Arc* left;
	Arc* right;

	//�ش� ȣ�� ���ϴ� Site
	Site* site;
	HalfEdge* leftHalfEdge;
	HalfEdge* rightHalfEdge;

	Arc* prev;
	Arc* next;
};