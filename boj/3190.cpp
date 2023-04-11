#include <vector>
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

int n, k, l;

int move_snake(vector<vector<int>>& board, vector<pair<int, char>>& turns) {
	int cnt = 0;

	// R, D, L, U
	int dx[4] = {0, 1, 0, -1};
	int dy[4] = {1, 0, -1, 0};
	int dir = 0;

	int x = 0, y = 0;
	queue<pair<int, int>> q;

	board[x][y] = 2;
	q.push(make_pair(x, y));

	int turnsIdx = 0;

	while (true) {
		if (turnsIdx < turns.size() && cnt == turns[turnsIdx].first) {
			if (turns[turnsIdx].second == 'D')
				dir = (dir + 1) % 4;
			else
				dir -= 1;
			if (dir < 0) dir = 3;

			turnsIdx += 1;
		}

		x += dx[dir];
		y += dy[dir];

		// Terminate Conditions
		if ((0 > x || x >= n) || (0 > y || y >= n)) break;
		if (board[x][y] == 2) break;

		q.push(make_pair(x, y));

		// Keep Moving
		if (board[x][y] == 0) {
			int tail_x = q.front().first;
			int tail_y = q.front().second;
			q.pop();

			board[tail_x][tail_y] = 0;
		}

		board[x][y] = 2;

		cnt += 1;
	}

	return cnt + 1;
}

int main() {
	scanf("%d %d", &n, &k);

	vector<vector<int>> board(n, vector<int>(n, 0));
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		board[x - 1][y - 1] = 1;
	}

	scanf("%d", &l);
	vector<pair<int, char>> turns(l);
	for (int i = 0; i < l; i++) {
		int t;
		char c;
		scanf("%d %c", &t, &c);
		turns[i] = make_pair(t, c);
	}

	printf("%d\n", move_snake(board, turns));

	return 0;
}