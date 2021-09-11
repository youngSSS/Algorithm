#include <string>
#include <vector>
#include <iostream>

using namespace std;

int check[20];
int visit[20][(1 << 20)];
int max_num = 0;

void dfs(int now_node, int bit, vector<int>& info, vector<vector<int>>& adj_list)
{
	int s = 0, w = 0;
	bit = bit | (1 << now_node);
	for (int i = 0; i < info.size(); i++)
	{
		if ((bit & (1 << i)) > 0)
		{
			if (info[i] == 0) s++;
			else w++;
		}
	}
	if (s <= w)
	{
		return;
	}
	if (s > max_num)
	{
		max_num = s;
	}
	if (visit[now_node][bit] > 0) return;
	else visit[now_node][bit] = 1;
	for (int i = 0; i < adj_list[now_node].size(); i++)
	{
		dfs(adj_list[now_node][i], bit, info, adj_list);
	}
}

int solution(vector<int> info, vector<vector<int>> edges)
{
	int answer = 1;
	vector<vector<int>> adj_list(info.size());
	for (int i = 0; i < edges.size(); i++)
	{
		adj_list[edges[i][0]].push_back(edges[i][1]);
		adj_list[edges[i][1]].push_back(edges[i][0]);
	}
	dfs(0, 0, info, adj_list);

	return max_num;
}

int main()
{
	cout << solution({ 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1 }, {{ 0, 1 },
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