#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;

pair<int, int> dfs(int t, vector<vector<int>>& board, vector<int> aloc, vector<int> bloc)
{
	int x1 = aloc[0], y1 = aloc[1];
	int x2 = bloc[0], y2 = bloc[1];

	if (board[x1][y1] == 0)
	{
		return make_pair(1, t);
	}
	if (board[x2][y2] == 0) return make_pair(0, t);

	if (t % 2 == 0)
	{
		int flag = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x1 + dx[i];
			int ny = y1 + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				if (board[nx][ny] == 1)
				{
					flag = 1;
				}
			}
		}
		if (flag == 0)
		{
			return make_pair(1, t);
		}
		int can_win = 0;
		int min_dist = 1e9;
		int max_dist = 0;
		board[x1][y1] = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x1 + dx[i];
			int ny = y1 + dy[i];
			pair<int, int> result;
			if (0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				result = dfs(t + 1, board, { nx, ny }, bloc);
				if (t == 0)
				{
					cout << result.first << result.second << endl;
				}
				if (result.first == 0)
				{
					can_win = 1;
					if (result.second < min_dist)
					{
						min_dist = result.second;
					}
				}
				else
				{
					if (result.second > max_dist)
					{
						max_dist = result.second;
					}
				}
			}
		}
		board[x1][y1] = 1;
		if (can_win == 0)
		{
			return make_pair(1, max_dist);
		}
		else
		{
			return make_pair(0, min_dist);
		}
	}


	if (t % 2 == 1)
	{
		int flag = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x2 + dx[i];
			int ny = y2 + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				if (board[nx][ny] == 1)
				{
					flag = 1;
				}
			}
		}
		if (flag == 0)
		{
			return make_pair(0, t);
		}
		int can_win = 0;
		int min_dist = 1e9;
		int max_dist = 0;
		board[x2][y2] = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = x2 + dx[i];
			int ny = y2 + dy[i];
			pair<int, int> result;
			if (0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				result = dfs(t + 1, board, aloc, { nx, ny });
				if (result.first == 1)
				{
					can_win = 1;
					if (result.second < min_dist)
					{
						min_dist = result.second;
					}
				}
				else
				{
					if (result.second > max_dist)
					{
						max_dist = result.second;
					}
				}
			}
		}
		board[x2][y2] = 1;
		if (can_win == 0)
		{
			return make_pair(0, max_dist);
		}
		else
		{
			return make_pair(1, min_dist);
		}

	}
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc)
{
	n = board.size();
	m = board[0].size();
	int answer = -1;
	pair<int, int> result;
	result = dfs(0, board, aloc, bloc);
	return result.second;
}

int main()
{
	cout << solution({{ 1 }}, { 0, 0 }, { 0, 0 });
	return 0;
}
