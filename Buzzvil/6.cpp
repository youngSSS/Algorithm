vector<vector<int>> graph;
vector<int> visit, in_edge;
int cnt;

void dfs(int idx) {
	visit[idx] = 1;
	cnt += 1;

	for (int i = 0; i < graph[idx].size(); i++) {
		int next = graph[idx][i];

		if (visit[next] == 0) dfs(next);
	}
}

int connectedSum(int graph_nodes, vector<int> graph_from, vector<int> graph_to) {
	int ans = 0;

	graph.resize(graph_nodes);
	visit.resize(graph_nodes, 0);
	in_edge.resize(graph_nodes, 0);

	for (int i = 0; i < graph_from.size(); i++) {
		graph[graph_from[i] - 1].push_back(graph_to[i] - 1);
		graph[graph_to[i] - 1].push_back(graph_from[i] - 1);
		in_edge[graph_to[i] - 1] = 1;
	}

	for (int i = 0; i < graph_nodes; i++) {
		if (in_edge[i] == 0 && visit[i] == 0) {
			cnt = 0;
			dfs(i);
			ans += ceil(sqrt(cnt));
		}
	}

	return ans;
}