﻿#include <iostream>
#include <list>
#include <vector>
#include <limits>
#include <queue>
#include <iomanip>

using namespace std;

// 간선을 저장하는 구조 사용 (문제에 따라 적절한 자료구조 사용)
// Sedgewick p. 642
class DirectedEdge
{
public:
	int v;         // 간선 시작(edge tail, 화살표 꼬리) 정점의 인덱스
	int w;         // 간선 끝(edge head, 화살촉) 정점의 인덱스
	double weight; // edge weight

	DirectedEdge(int v, int w, double weight)
	{
		this->v = v;
		this->w = w;
		this->weight = weight;
	}

	double Weight() { return weight; }
	int From() { return v; }
	int To() { return w; }
};

// 간선에 가중치가 있는 방향성 그래프
class EdgeWeightedDigraph
{
public:
	int num_vertices;
	int num_edges;
	vector<vector<DirectedEdge>> adj; // 여기서는 Edge를 기록하는 자료구조

	EdgeWeightedDigraph(int num_vertices)
	{
		this->num_vertices = num_vertices;
		this->num_edges = 0;
		adj.resize(this->num_vertices);
	}

	void AddEdge(DirectedEdge e)
	{
		adj[e.From()].push_back(e);
		num_edges += 1;
	}

	vector<DirectedEdge>& Adj(int v) { return adj[v]; }
};

// 최단거리 찾기만을 수행하는 클래스
// 그래프 자체는 다른 클래스 사용
class DijkstraShortestPaths
{
public:
	DijkstraShortestPaths(EdgeWeightedDigraph& g, int s)
		:
		prev(g.num_vertices, -1),
		dist(g.num_vertices, numeric_limits<double>::infinity()), // 일단 전부 무한대 거리로 초기화
		visited(g.num_vertices, false)
	{
		dist[s] = 0.0; // 자기자신과의 거리는 0

		PrintIndex(dist);
		PrintDist(dist);

		while (true)
		{
			int v = FindMinVertex();

			if (v < 0) break;

			cout << "Visit " << v << endl;

			visited[v] = true;

			Relax(g, v);
		}

		PrintPaths(); // 최단 경로 출력
	}

	int FindMinVertex()
	{
		//TODO: 아직 방문하지 않은 정점들 중에서 dist가 가장 작은 것의 인덱스를 반환
		double minv = numeric_limits<double>::infinity();
		int idx;
		for(int i = 0; i < dist.size();i++){
			if(!visited[i] && dist[i] < minv) {
				minv = dist[i];
				idx = i;
			}
		}

		return minv ==  numeric_limits<double>::infinity() ? -1 : idx;
	}

	// 여기서 Relax는 점점 긴장을 풀어간다는 의미입니다.
	// 정답을 한 번에 찾는 방식이 아니라 반복(iteration)하면서 
	// 제약 조건을 조금씩 완화시켜간다는 표현입니다.
	void Relax(EdgeWeightedDigraph& g, int v)
	{
		cout << v << endl;

		//TODO: 
		for ( DirectedEdge& vec : g.Adj(v) )
		{
			// dist[v]: s에서 v까지 오기 위해 현재까지 발견된 최소거리 경로
			// v에서 다시 w로 이동할 경우 dist 업데이트

			int w = vec.w;

			double new_dist = dist[v] + vec.weight;
			if ( new_dist < dist[w] ) // w까지 오는 새로운 최단 경로 발견
			{
				dist[w] = new_dist;

				prev[w] = v; // 최단 경로 기록

				// if (pq.Contains(w)) {
				// 	pq.DecreaseKey(w, dist[w]);
				// } else {
				// 	pq.Insert(w, dist[w]);
				// }
			}
		}
		
		PrintDist(dist);
	}

	void PrintIndex(vector<double>& dist)
	{
		cout << "Vertex: ";
		for (int i = 0; i < dist.size(); i++)
			cout << setw(6) << i;
		cout << endl;
	}

	void PrintDist(vector<double>& dist)
	{
		cout << "Dist  : ";
		for (int i = 0; i < dist.size(); i++)
			cout << setw(6) << dist[i];
		cout << endl;
	}

	void PrintPaths()
	{
		// TODO: prev 이용
		for(int i = 0; i<dist.size();i++){
			deque<int> path;
			path.push_front(i);
			int v = prev[i];
			while (v != -1)
			{
				path.push_front(v);
				v = prev[v];
			}


			for (auto v : path) {
				cout << v;
				if (v != path.back())
					cout << " -> ";
			}
			cout << endl;

		}
	}

private:
	vector<int> prev;     // 최단 경로 기록
	vector<double> dist;  // 거리 기록
	vector<bool> visited; // 방문했는지 기록
};

int main()
{
	// CLRS p.621
	{
		vector<DirectedEdge> edges = {
		{0, 1, 10.0},
		{0, 3, 5.0},
		{1, 2, 1.0},
		{1, 3, 2.0},
		{2, 4, 4.0},
		{3, 1, 3.0},
		{3, 2, 9.0},
		{3, 4, 2.0},
		{4, 0, 7.0},
		{4, 2, 6.0},
		};

		EdgeWeightedDigraph g(5);

		for (auto e : edges)
			g.AddEdge(e);

		DijkstraShortestPaths d(g, 0);
	}
}
