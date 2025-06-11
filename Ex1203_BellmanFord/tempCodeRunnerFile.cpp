vector<Edge> edges = {
	{0, 1, 1.0}, // A->B 1
	{1, 2, 5.0},
	{1, 3, 4.0},
	{2, 3, -3.0},
	{3, 4, 1.0},
	{4, 3, -100.0} // 음의 싸이클이 추가된 경우
	};
	int V = 5; // number of vertices

	std::reverse(edges.begin(), edges.end()); // 간선 순서 뒤집어서 해보기