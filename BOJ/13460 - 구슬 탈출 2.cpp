#include <string>
#include <vector>
#include <iostream>

using namespace std;

// R, D, L, U
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int answer = 1e9;
int n, m;

vector<vector<int>> r_visit, b_visit;

void dfs(vector<vector<int>> board, int cnt, pair<int, int> r_pos, pair<int, int> b_pos) {
	if (cnt > 10) return;

	for (int i = 0; i < 4; i++) {
		int rx = r_pos.first;
		int ry = r_pos.second;
		int bx = b_pos.first;
		int by = b_pos.second;

		int x1, y1, x2, y2;
		int is_x1_red = 1;

		vector<vector<int>> new_board = board;

		if (i == 0 && rx == bx) {
			if (ry > by) {
				x1 = rx;
				y1 = ry;
				x2 = bx;
				y2 = by;
			}
			else {
				is_x1_red = 0;
				x1 = bx;
				y1 = by;
				x2 = rx;
				y2 = ry;
			}
		}
		else if (i == 2 && rx == bx) {
			if (ry > by) {
				is_x1_red = 0;
				x1 = bx;
				y1 = by;
				x2 = rx;
				y2 = ry;
			}
			else {
				x1 = rx;
				y1 = ry;
				x2 = bx;
				y2 = by;
			}
		}
		else if (i == 1 && ry == by) {
			if (rx > bx) {
				x1 = rx;
				y1 = ry;
				x2 = bx;
				y2 = by;
			}
			else {
				is_x1_red = 0;
				x1 = bx;
				y1 = by;
				x2 = rx;
				y2 = ry;
			}
		}
		else if (i == 3 && ry == by) {
			if (rx > bx) {
				is_x1_red = 0;
				x1 = bx;
				y1 = by;
				x2 = rx;
				y2 = ry;
			}
			else {
				x1 = rx;
				y1 = ry;
				x2 = bx;
				y2 = by;
			}
		}
		else {
			x1 = rx;
			y1 = ry;
			x2 = bx;
			y2 = by;
		}

		int red_flag = 0, blue_flag = 0;

		while (0 <= x1 + dx[i] && x1 + dx[i] < n && 0 <= y1 + dy[i] && y1 + dy[i] < m) {
			x1 += dx[i];
			y1 += dy[i];

			if (new_board[x1][y1] == 0) {
				x1 -= dx[i];
				y1 -= dy[i];

				if (is_x1_red) {
					new_board[rx][ry] = 1;
					new_board[x1][y1] = 2;
				}
				else {
					new_board[bx][by] = 1;
					new_board[x1][y1] = 3;
				}

				break;
			}
			else if (new_board[x1][y1] == 4) {
				if (is_x1_red) {
					new_board[rx][ry] = 1;
					red_flag = 1;
				}
				else {
					new_board[bx][by] = 1;
					blue_flag = 1;
				}

				break;
			}
		}

		while (0 <= x2 + dx[i] && x2 + dx[i] < n && 0 <= y2 + dy[i] && y2 + dy[i] < m) {
			x2 += dx[i];
			y2 += dy[i];

			if (new_board[x2][y2] == 0 || new_board[x2][y2] == 2 || new_board[x2][y2] == 3) {
				x2 -= dx[i];
				y2 -= dy[i];

				if (is_x1_red) {
					new_board[bx][by] = 1;
					new_board[x2][y2] = 3;
				}
				else {
					new_board[rx][ry] = 1;
					new_board[x2][y2] = 2;
				}

				break;
			}
			else if (new_board[x2][y2] == 4) {
				if (is_x1_red) {
					new_board[bx][by] = 1;
					blue_flag = 1;
				}
				else {
					new_board[rx][ry] = 1;
					red_flag = 1;
				}

				break;
			}
		}

		if (blue_flag == 1) continue;
		else if (red_flag == 1) {
			if (answer > cnt) answer = cnt;
			continue;
		}

		if (is_x1_red) {
			if (rx == x1 && ry == y1 && bx == x2 && by == y2) continue;
		}
		else {
			if (bx == x1 && by == y1 && rx == x2 && ry == y2) continue;
		}

		if (is_x1_red) dfs(new_board, cnt + 1, make_pair(x1, y1), make_pair(x2, y2));
		else dfs(new_board, cnt + 1, make_pair(x2, y2), make_pair(x1, y1));
	}
}

int main() {
	scanf("%d %d", &n, &m);
	vector<vector<int>> board(n, vector<int>(m));
	r_visit.resize(n, vector<int>(m));
	b_visit.resize(n, vector<int>(m));

	pair<int, int> r_pos, b_pos;
	for (int i = 0; i < n; i++) {
		string row;
		cin >> row;
		for (int j = 0; j < m; j++) {
			if (row[j] == '#') board[i][j] = 0;
			else if (row[j] == '.') board[i][j] = 1;
			else if (row[j] == 'R') {
				board[i][j] = 2;
				r_pos = {i, j};
			}
			else if (row[j] == 'B') {
				board[i][j] = 3;
				b_pos = {i, j};
			}
			else if (row[j] == 'O') board[i][j] = 4;
		}
	}

	dfs(board, 1, r_pos, b_pos);
	if (answer == 1e9) printf("-1\n");
	else printf("%d\n", answer);

	return 0;
}