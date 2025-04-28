
#include <iostream>
#include <list>
#include <vector>
// #include <algorithm>

using namespace std;

struct Vertex
{
	Vertex(int v) { value = v; }

	int value = -1;// 변수 이름은 value지만 실질적으로는 배열에 이 정점이 저장된 인덱스입니다.
	bool visited = false;

	vector<Vertex*> out_neighbors; // 나가는 방향의 이웃 vertex들에 대한 포인터
	vector<Vertex*> in_neighbors;  // 들어오는 방향의 이웃 vertex들에 대한 포인터
};

class Graph
{
public:
	Graph(int num_vertices)
	{
		vertices.resize(num_vertices);
		for (int i = 0; i < num_vertices; i++)
			vertices[i] = new Vertex(i);
	}

	~Graph()
	{
		for (auto* v : vertices)
			delete v;
	}

	void AddDiEdge(int v, int w) // 단방향 간선
	{
		vertices[v]->out_neighbors.push_back(vertices[w]);
		vertices[w]->in_neighbors.push_back(vertices[v]);
	}

	bool HasPath(int start, int target)
	{
		for (auto* v : vertices)
			v->visited = false;
		return HasPathHelper(vertices[start], vertices[target]);
	}

	void BruteForceStrongComponents()
	{
		int count = 0;
		vector<int> id(vertices.size(), -1);

		// TODO: HasPath()를 이용해서 서로 강하게 연결된 요소들을 찾습니다.
		for(int i = 0; i<vertices.size(); i++){
			if(id[i] != -1) continue;
			// 실수 : 해당 부분에 id[i]를 업데이트 하지 않으면, 결국 결과 처리 시 component[id[s] = -1] 이라서 잘못 참조되어 코드가 터짐 
			id[i] = count;
			for(int j = 0; j<vertices.size(); j++){
				if(i == j) continue;
				if(id[j] != -1) continue;

				if(HasPath(i, j) && HasPath(j, i)){
					id[j] = count;
				}
			}

			count++;
		}

		// 결과 정리 후 출력
		vector<vector<int>> components(count);
		for (int s = 0; s < vertices.size(); s++)
			components[id[s]].push_back(s);
		cout << count << " strong components" << endl;
		for (int i = 0; i < components.size(); i++)
		{
			cout << "Strong component " << i + 1 << ": ";
			for (auto v : components[i])
				cout << v << " ";
			cout << endl;
		}
	}

private:
	vector<Vertex*> vertices;

	bool HasPathHelper(Vertex* v, Vertex* t)
	{	
		if(v == t) return true; // 목적지에 도달했으면 true를 반환합니다.
		v->visited = true; // 방문 표시

		// 모든 나가는 이웃을 확인합니다.
		for(auto* next : v->out_neighbors) {
			if(!next->visited) { // 방문하지 않은 이웃만 처리합니다.
				if(HasPathHelper(next, t)) { // 재귀적으로 경로를 찾습니다.
					return true; // 경로를 찾았으면 true를 반환합니다.
				}
			}
		}

		return false; // 경로를 찾지 못했으면 false를 반환합니다.
	}
};

int main()
{
	// Sedgewick p569
	// 방향(directed) 그래프
	vector<vector<int>> edges = {
		{4, 2}, {2, 3}, {3, 2}, {6, 0}, {0, 1}, {2, 0}, {11, 12}, {12, 9}, {9, 10},
		{9, 11}, {7, 9}, {10, 12}, {11, 4}, {4, 3}, {3, 5}, {6, 8}, {8, 6}, {5, 4},
		{0, 5}, {6, 4}, {6, 9}, {7, 6} };

	Graph g(13);

	for (vector<int>& p : edges)
		g.AddDiEdge(p[0], p[1]);

	g.BruteForceStrongComponents();

	return 0;
}
