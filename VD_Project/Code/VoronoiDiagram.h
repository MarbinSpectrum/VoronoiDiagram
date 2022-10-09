#pragma once

////#include "fieldData.h"
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <set>
//
////using namespace std;
//
////#define endl "\n"
////#define int long long
//#define longDouble long double
//
//const longDouble EPS = 1e-12;
//const longDouble INF = 1e100;
//const int Dic[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
//
////////////////////////////////////////////////////////////////////////// 
//
//struct arc;
//struct Vector2;
//
////x좌표 기준으로 sweepline을 형성한다.
//longDouble sweepX;
//
//std::vector<Vector2> arr;
//
//struct Vector2
//{
//	longDouble x, y;
//	Vector2(longDouble pX = 0, longDouble pY = 0)
//		: x(pX)
//		, y(pY)
//	{
//	}
//
//	Vector2 operator+(const Vector2& a) const
//	{
//		return Vector2(x + a.x, y + a.y);
//	}
//
//	Vector2 operator-(const Vector2& a) const
//	{
//		return Vector2(x - a.x, y - a.y);
//	}
//
//	Vector2 operator*(const longDouble& a) const
//	{
//		return Vector2(x * a, y * a);
//	}
//
//	bool operator<(const Vector2& a) const
//	{
//		return std::make_pair(x, y) < std::make_pair(a.x, a.y);
//	}
//
//	//시계방향으로 90인 벡터
//	Vector2 Rotate() const
//	{
//		return Vector2(-y, x);
//	}
//
//	//내적
//	longDouble Dot(const Vector2& a) const
//	{
//		return x * a.x + y * a.y;
//	}
//
//	//외적
//	longDouble Cross(const Vector2& a) const
//	{
//		return x * a.y - y * a.x;
//	}
//
//	//벡터 길이
//	longDouble Len() const
//	{
//		return sqrt(x * x + y * y);
//	}
//
//};
//
////벡터가 평행(만나지 않는지) 검사한다.
//bool Collinear(const Vector2& a, const Vector2& b)
//{
//	return abs(a.Cross(b)) < EPS;
//}
//
////ab간선과 cd간선의 교차점을 구한다.
//Vector2 LineInterSectionPoint(const Vector2& a, const Vector2& b, const Vector2& c, const Vector2& d)
//{
//	return a + (b - a) * ((c - a).Cross(d - c) / (b - a).Cross(d - c));
//
//	//float p = (a.x - b.x) * (c.y - d.y) - (a.y - b.y) * (c.x - d.x);
//	//float px = a.Cross(b) * (c.x - d.x) - (a.x - b.x) * c.Cross(d);
//	//float py = a.Cross(b) * (c.y - d.y) - (a.y - b.y) * c.Cross(d);
//	//px /= p;
//	//py /= p;
//
//	//Vector2 res(px, py);
//	//return res;
//}
//
////a,b,c의 외접원의 중심을 구한다.
//Vector2 CircumCircleCenter(Vector2 a, Vector2 b, Vector2 c)
//{
//	b = (a + b) * 0.5;
//	c = (a + c) * 0.5;
//	return LineInterSectionPoint(b, b + (b - a).Rotate(), c, c + (c - a).Rotate());
//
//	//Vector2 abCenter = (a + b) * 0.5;
//	//Vector2 acCenter = (a + c) * 0.5;
//
//	//Vector2 p0 = abCenter;
//	//Vector2 p1 = abCenter + (abCenter - a).Rotate();
//	//Vector2 p2 = acCenter;
//	//Vector2 p3 = acCenter + (acCenter - a).Rotate();
//
//	//Vector2 res = LineInterSectionPoint(p0, p1, p2, p3);
//
//	//return res;
//}
//
//struct arc
//{
//	mutable Vector2 p; //호의 정점
//	mutable Vector2 q;
//	mutable int id = 0;
//	mutable int idx = 0;
//	arc(Vector2 pP, Vector2 pQ, int pIdx)
//	: p(pP)
//	, q(pQ)
//	, idx(pIdx)
//	{
//	}
//
//	//해당 x좌표에 해당하는 호의 y좌표 
//	longDouble GetY(longDouble x) const
//	{
//		if (q.y == INF) return INF;
//		x += EPS;
//		Vector2 med = (p + q) * 0.5;
//		Vector2 dir = (p - med).Rotate();
//		longDouble D = (x - p.x) * (x - q.x);
//		return med.y + ((med.x - x) * dir.x + sqrtl(D) * dir.Len()) / dir.y;
//
//
//		//if (q.y == INF)
//		//	return INF;
//		//x += EPS;
//		//Vector2 med = (p + q) * 0.5;
//		//Vector2 dir = (p - med).Rotate();
//		//float D = (x - p.x) * (x - q.x);
//		//return med.y + ((med.x - x) * dir.x + sqrtl(D) * dir.Len()) / dir.y;
//	}
//
//	bool operator<(const longDouble& y) const
//	{
//		return GetY(sweepX) < y;
//	}
//	bool operator<(const arc& a) const
//	{
//		return GetY(sweepX) < a.GetY(sweepX);
//	}
//};
//
//using beach = std::multiset<arc, std::less<>>;
//
//struct Event
//{
//	//이벤트
//	longDouble x;
//	int id;
//	beach::iterator it;
//	Event(longDouble pX, int pId, beach::iterator pIt)
//		: x(pX)
//		, id(pId)
//		, it(pIt)
//	{
//	}
//
//	bool operator<(const Event& e) const
//	{
//		return x > e.x;
//	}
//};
//
//beach beachLine; //arc값을 arc.x기준으로 내림차순으로 가지고 있는 set
//std::vector<std::pair<Vector2, int>> v; //(점좌표,원래 Idx)
//std::priority_queue<Event> pq; //이벤트를 관리할 우선순위큐
//std::vector<std::pair<int, int>> edges; //들로네 삼각분할로 생긴 경계선(시작 원래 Idx,끝 원래 Idx)
//std::vector<bool> valid; //해당 ID를 가진 vertexEvent가 유효한 경우 (valid[-id] == true)
//
//int N; //정점의 갯수
//int ti; //다음 정점 ID
//void Init(std::vector<Vector2> p)
//{
//	//정점을 대입한다.
//	N = p.size();
//	v.clear();
//	v.resize(N);
//	for (int i = 0; i < N; i++)
//		v[i] = { p[i],i };
//	sort(v.begin(), v.end());
//}
//
//void Update(beach::iterator it)
//{
//	if (it->idx == -1)
//	{
//		//잘못된점?
//		return;
//	}
//	valid[-(it->id)] = false; //이벤트가 유효하지않다고 체크
//	auto a = prev(it);
//
//	if (Collinear((it->q - it->p), (a->p - it->p)))
//	{
//		//평행하다 vertexEvent를 만들지 않는다.
//		return;
//	}
//
//	it->id = --ti; //새로운 vertexEvent ID를 배정
//	valid.push_back(true);
//	Vector2 c = CircumCircleCenter(it->p, it->q, a->p);
//	longDouble x = c.x + (c - it->p).Len();
//
//	if (x > sweepX - EPS && a->GetY(x) + EPS > it->GetY(x))
//	{
//		pq.push(Event(x, it->id, it));
//	}
//}
//
////들로네 경계선 추가
//void AddEdge(int i, int j)
//{
//	if (i == -1 || j == -1)
//		return;
//	edges.push_back({ v[i].second,v[j].second });
//}
//
////pointEvent 처리
//void Add(int idx)
//{
//	Vector2 p = v[idx].first;
//
//	// 호를 가져온다.
//	auto c = beachLine.lower_bound(p.y);
//
//	//새로운 호를 삽인한다.
//	auto b = beachLine.insert(c, arc(p, c->p, idx));
//	auto a = beachLine.insert(b, arc(c->p, p, c->idx));
//	AddEdge(idx, c->idx);
//	Update(a);
//	Update(b);
//	Update(c);
//}
//
//void Remove(beach::iterator it)
//{
//	auto a = prev(it);
//	auto b = next(it);
//	beachLine.erase(it);
//	a->q = b->p;
//	AddEdge(a->idx, b->idx);
//	Update(a);
//	Update(b);
//}
//
//void Solve(longDouble x = 1e9) //x는 모든 좌표를 초과하는 값
//{
//	//호가 가장자리 케이스를 처리하지 않게하기 위해서 beachline에 두개의 점을 추가
//	x *= 3;
//	beachLine.insert(arc(Vector2(-x, -x), Vector2(-x, x), -1));
//	beachLine.insert(arc(Vector2(-x, x), Vector2(INF, INF), -1));
//
//	for (int i = 0; i < N; i++)
//	{
//		pq.push(Event(v[i].first.x, i, beachLine.end()));
//	}
//	ti = 0;
//	valid.assign(1, false);
//
//	while (pq.empty() == false)
//	{
//		Event e = pq.top();
//		pq.pop();
//		sweepX = e.x;
//		if (e.id >= 0)
//		{
//			Add(e.id);
//		}
//		else if (valid[-e.id])
//		{
//			Remove(e.it);
//		}
//	}
//}

#include<vector>
#include<tuple>
#include<queue>
#include<cmath>
#include<algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const double EPS = 1e-9;
int dcmp(double x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }

double operator / (pdd a, pdd b) { return a.first * b.second - a.second * b.first; }
pdd    operator * (double b, pdd a) { return pdd(b * a.first, b * a.second); }
pdd    operator + (pdd a, pdd b) { return pdd(a.first + b.first, a.second + b.second); }
pdd    operator - (pdd a, pdd b) { return pdd(a.first - b.first, a.second - b.second); }

double sq(double x) { return x * x; }
double size(pdd p) { return hypot(p.first, p.second); }
double sz2(pdd p) { return sq(p.first) + sq(p.second); }
pdd r90(pdd p) { return pdd(-p.second, p.first); }

pdd line_intersect(pdd a, pdd b, pdd u, pdd v) { return u + (((a - u) / b) / (v / b)) * v; }
pdd get_circumcenter(pdd p0, pdd p1, pdd p2) {
	return line_intersect(0.5 * (p0 + p1), r90(p0 - p1), 0.5 * (p1 + p2), r90(p1 - p2));
}

// https://www.youtube.com/watch?v=h_vvP4ah6Ck
double parabola_intersect(pdd left, pdd right, double sweepline) {
	/*
	if(dcmp(left.second - right.second) == 0) return (left.first + right.first) / 2.0; /*/
	auto f2 = [](pdd left, pdd right, double sweepline) {
		int sign = left.first < right.first ? 1 : -1;
		pdd m = 0.5 * (left + right);
		pdd v = line_intersect(m, r90(right - left), pdd(0, sweepline), pdd(1, 0));
		pdd w = line_intersect(m, r90(left - v), v, left - v);
		double l1 = size(v - w), l2 = sqrt(sq(sweepline - m.second) - sz2(m - w)), l3 = size(left - v);
		return v.first + (m.first - v.first) * l3 / (l1 + sign * l2);
	};
	if (fabs(left.second - right.second) < fabs(left.first - right.first) * EPS) return f2(left, right, sweepline);// */
	int sign = left.second < right.second ? -1 : 1;
	pdd v = line_intersect(left, right - left, pdd(0, sweepline), pdd(1, 0));
	double d1 = sz2(0.5 * (left + right) - v), d2 = sz2(0.5 * (left - right));
	return v.first + sign * sqrt(max(0.0, d1 - d2));
}

class Beachline {
public:
	struct node {
		node() {}
		node(pdd point, int idx) :point(point), idx(idx), end(0),
			link{ 0, 0 }, par(0), prv(0), nxt(0) {}
		pdd point; int idx; int end;
		node* link[2], * par, * prv, * nxt;
	};
	node* root;
	double sweepline;

	Beachline() : sweepline(-1e20), root(NULL) { }
	inline int dir(node* x) { return x->par->link[0] != x; }

	//     p        n          p            n
	//    / \      / \        / \          / \
		//   n   d => a   p   or a   n   =>   p   d
		//  / \          / \        / \      / \
		// a   b        b   d      c   d    a   c

	void rotate(node* n) {
		node* p = n->par;         int d = dir(n);
		p->link[d] = n->link[!d]; if (n->link[!d]) n->link[!d]->par = p;
		n->par = p->par;          if (p->par) p->par->link[dir(p)] = n;
		n->link[!d] = p;          p->par = n;
	}

	void splay(node* x, node* f = NULL) {
		while (x->par != f) {
			if (x->par->par == f);
			else if (dir(x) == dir(x->par)) rotate(x->par);
			else rotate(x);
			rotate(x);
		}
		if (f == NULL) root = x;
	}

	void insert(node* n, node* p, int d) {
		splay(p); node* c = p->link[d];
		n->link[d] = c; if (c) c->par = n;
		p->link[d] = n; n->par = p;

		node* prv = !d ? p->prv : p, * nxt = !d ? p : p->nxt;
		n->prv = prv;   if (prv) prv->nxt = n;
		n->nxt = nxt;   if (nxt) nxt->prv = n;
	}

	void erase(node* n) {
		node* prv = n->prv, * nxt = n->nxt;
		if (!prv && !nxt) { if (n == root) root = NULL; return; }
		n->prv = NULL;   if (prv) prv->nxt = nxt;
		n->nxt = NULL;   if (nxt) nxt->prv = prv;
		splay(n);
		if (!nxt) {
			root->par = NULL; n->link[0] = NULL;
			root = prv;
		}
		else {
			splay(nxt, n);     node* c = n->link[0];
			nxt->link[0] = c;  c->par = nxt;         n->link[0] = NULL;
			n->link[1] = NULL; nxt->par = NULL;
			root = nxt;
		}
	}
	bool get_event(node* cur, double& next_sweep) {
		if (!cur->prv || !cur->nxt) return false;
		pdd u = r90(cur->point - cur->prv->point);
		pdd v = r90(cur->nxt->point - cur->point);
		if (dcmp(u / v) != 1) return false;
		pdd p = get_circumcenter(cur->point, cur->prv->point, cur->nxt->point);
		next_sweep = p.second + size(p - cur->point);
		return true;
	}
	node* find_beachline(double x) {
		node* cur = root;
		while (cur) {
			double left = cur->prv ? parabola_intersect(cur->prv->point, cur->point, sweepline) : -1e30;
			double right = cur->nxt ? parabola_intersect(cur->point, cur->nxt->point, sweepline) : 1e30;
			if (left <= x && x <= right) { splay(cur); return cur; }
			cur = cur->link[x > right];
		}
	}
}; using BeachNode = Beachline::node;

static BeachNode* arr;
static int sz;
static BeachNode* new_node(pdd point, int idx) {
	arr[sz] = BeachNode(point, idx);
	return arr + (sz++);
}

struct event {
	event(double sweep, int idx) : type(0), sweep(sweep), idx(idx) {}
	event(double sweep, BeachNode* cur) : type(1), sweep(sweep), prv(cur->prv->idx), cur(cur), nxt(cur->nxt->idx) {}
	int type, idx, prv, nxt;
	BeachNode* cur;
	double sweep;
	bool operator>(const event& l)const { return sweep > l.sweep; }
};

void VoronoiDiagram(vector<pdd>& input, vector<pdd>& vertex, vector<pii>& edge, vector<pii>& area) {
	Beachline beachline = Beachline();
	priority_queue<event, vector<event>, greater<event>> events;

	auto add_edge = [&](int u, int v, int a, int b, BeachNode* c1, BeachNode* c2) {
		if (c1) c1->end = edge.size() * 2;
		if (c2) c2->end = edge.size() * 2 + 1;
		edge.emplace_back(u, v);
		area.emplace_back(a, b);
	};
	auto write_edge = [&](int idx, int v) { idx % 2 == 0 ? edge[idx / 2].first = v : edge[idx / 2].second = v; };
	auto add_event = [&](BeachNode* cur) { double nxt; if (beachline.get_event(cur, nxt)) events.emplace(nxt, cur); };

	int n = input.size(), cnt = 0;
	arr = new BeachNode[n * 4]; sz = 0;
	sort(input.begin(), input.end(), [](const pdd& l, const pdd& r) {
		return l.second != r.second ? l.second < r.second : l.first < r.first;
		});

	BeachNode* tmp = beachline.root = new_node(input[0], 0), *t2;
	for (int i = 1; i < n; i++) {
		if (dcmp(input[i].second - input[0].second) == 0) {
			add_edge(-1, -1, i - 1, i, 0, tmp);
			beachline.insert(t2 = new_node(input[i], i), tmp, 1);
			tmp = t2;
		}
		else events.emplace(input[i].second, i);
	}
	while (events.size()) {
		event q = events.top(); events.pop();
		BeachNode* prv, * cur, * nxt, * site;
		int v = vertex.size(), idx = q.idx;
		beachline.sweepline = q.sweep;
		if (q.type == 0) {
			pdd point = input[idx];
			cur = beachline.find_beachline(point.first);
			beachline.insert(site = new_node(point, idx), cur, 0);
			beachline.insert(prv = new_node(cur->point, cur->idx), site, 0);
			add_edge(-1, -1, cur->idx, idx, site, prv);
			add_event(prv); add_event(cur);
		}
		else {
			cur = q.cur, prv = cur->prv, nxt = cur->nxt;
			if (!prv || !nxt || prv->idx != q.prv || nxt->idx != q.nxt) continue;
			vertex.push_back(get_circumcenter(prv->point, nxt->point, cur->point));
			write_edge(prv->end, v); write_edge(cur->end, v);
			add_edge(v, -1, prv->idx, nxt->idx, 0, prv);
			beachline.erase(cur);
			add_event(prv); add_event(nxt);
		}
	}
	delete arr;
}

std::vector<pdd> inputList;
std::vector<pdd> vertexList;
std::vector<pii> edgeList;
std::vector<pii> areaList;

class VoronoiDiagram
{
public:
	void Run();
private:
	//std::vector<Site> mSites;
	//std::vector<Face> mFaces;
	//std::vector<Vertex> mVertices;
	//std::vector<HalfEdge> mHalfEdges;
};