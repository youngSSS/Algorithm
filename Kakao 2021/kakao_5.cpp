#include <vector>
#include <iostream>

using namespace std;

int visit[20][(1 << 20)];
int max_num = 0;

void dfs(int now_node, int bit, vector<int>& info, vector<vector<int>>& adj_list) {
	int s = 0, w = 0;

	bit = bit | (1 << now_node);

	if (visit[now_node][bit] > 0) return;
	else visit[now_node][bit] = 1;

	for (int i = 0; i < info.size(); i++) {
		if ((bit & (1 << i)) > 0) {
			if (info[i] == 0) s++;
			else w++;
		}
	}

	if (s <= w) return;
	if (s > max_num) max_num = s;

	for (int i = 0; i < adj_list[now_node].size(); i++)
		dfs(adj_list[now_node][i], bit, info, adj_list);
}

int solution(vector<int> info, vector<vector<int>> edges) {
	vector<vector<int>> adj_list(info.size());

	for (auto edge : edges) {
		adj_list[edge[0]].push_back(edge[1]);
		adj_list[edge[1]].push_back(edge[0]);
	}

	dfs(0, 0, info, adj_list);

	return max_num;
}

int main() {
	cout << solution(
		{ 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1 },
		{
			{ 0, 1 },
			{ 1, 2 },
			{ 1, 4 },
			{ 0, 8 },
			{ 8, 7 },
			{ 9, 10 },
			{ 9, 11 },
			{ 4, 3 },
			{ 6, 5 },
			{ 4, 6 },
			{ 8, 9 }});
	return 0;
}