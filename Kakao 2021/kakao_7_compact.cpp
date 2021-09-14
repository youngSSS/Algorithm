#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int n, m;

pair<int, int> dfs(int t, vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
	int player = t % 2 == 0 ? 0 : 1;
	int x = player == 0 ? aloc[0] : bloc[0];
	int y = player == 0 ? aloc[1] : bloc[1];

	if (board[x][y] == 0) return make_pair(1 - player, t);

	pair<int, int> result;
	int flag = 0, can_win = 0;
	int min_dist = 1e9, max_dist = 0;

	board[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			flag = 1;

			if (player == 0) result = dfs(t + 1, board, { nx, ny }, bloc);
			else result = dfs(t + 1, board, aloc, { nx, ny });

			if (result.first == player) {
				can_win = 1;
				if (min_dist > result.second) min_dist = result.second;
			}
			else {
				if (max_dist < result.second) max_dist = result.second;
			}
		}
	}
	board[x][y] = 1;

	if (flag == 0) return make_pair(1 - player, t);

	if (can_win) return make_pair(player, min_dist);
	else return make_pair(1 - player, max_dist);
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
	n = board.size();
	m = board[0].size();
	pair<int, int> result = dfs(0, board, aloc, bloc);
	return result.second;
}

int main() {
	// Answer: 5
	cout << solution(
		{
			{ 1, 1, 1 },
			{ 1, 1, 1 },
			{ 1, 1, 1 }
		},
		{ 1, 0 },
		{ 1, 2 });
	return 0;
}
