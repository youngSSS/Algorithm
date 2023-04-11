#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int n;
int max_value = 0;

void dfs(vector<vector<int>> board, int cnt) {
	if (cnt == 5) {
		for (auto& row : board) {
			for (auto& item : row) {
				if (item > max_value) max_value = item;
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		vector<vector<int>> nboard = board;

		// Right
		if (i == 0) {
			for (int x = 0; x < n; x++) {
				int pos = n - 1;
				for (int y = n - 1; y >= 0; y--) {
					if (nboard[x][y] == 0) continue;

					int ny = y - 1;
					while (ny >= 0) {
						if (nboard[x][ny] != 0) break;
						ny -= 1;
					}

					if (ny < 0) {
						nboard[x][pos] = nboard[x][y];
						if (pos != y) nboard[x][y] = 0;
						break;
					}

					if (nboard[x][ny] == nboard[x][y]) {
						nboard[x][pos] = nboard[x][y] * 2;
						nboard[x][ny] = 0;
						if (pos != y) nboard[x][y] = 0;
						y = ny;
					}
					else {
						nboard[x][pos] = nboard[x][y];
						if (pos != y) nboard[x][y] = 0;
						y = ny + 1;
					}

					pos -= 1;
				}
			}
		}

			// Down
		else if (i == 1) {
			for (int y = 0; y < n; y++) {
				int pos = n - 1;
				for (int x = n - 1; x >= 0; x--) {
					if (nboard[x][y] == 0) continue;

					int nx = x - 1;
					while (nx >= 0) {
						if (nboard[nx][y] != 0) break;
						nx -= 1;
					}

					if (nx < 0) {
						nboard[pos][y] = nboard[x][y];
						if (pos != x) nboard[x][y] = 0;
						break;
					}

					if (nboard[nx][y] == nboard[x][y]) {
						nboard[pos][y] = nboard[x][y] * 2;
						nboard[nx][y] = 0;
						if (pos != x) nboard[x][y] = 0;
						x = nx;
					}
					else {
						nboard[pos][y] = nboard[x][y];
						if (pos != x) nboard[x][y] = 0;
						x = nx + 1;
					}

					pos -= 1;
				}
			}
		}

			// Left
		else if (i == 2) {
			for (int x = 0; x < n; x++) {
				int pos = 0;
				for (int y = 0; y < n; y++) {
					if (nboard[x][y] == 0) continue;

					int ny = y + 1;
					while (ny < n) {
						if (nboard[x][ny] != 0) break;
						ny += 1;
					}

					if (ny >= n) {
						nboard[x][pos] = nboard[x][y];
						if (pos != y) nboard[x][y] = 0;
						break;
					}

					if (nboard[x][ny] == nboard[x][y]) {
						nboard[x][pos] = nboard[x][y] * 2;
						nboard[x][ny] = 0;
						if (pos != y) nboard[x][y] = 0;
						y = ny;
					}
					else {
						nboard[x][pos] = nboard[x][y];
						if (pos != y) nboard[x][y] = 0;
						y = ny - 1;
					}

					pos += 1;
				}
			}
		}

			// Up
		else if (i == 3) {
			for (int y = 0; y < n; y++) {
				int pos = 0;
				for (int x = 0; x < n; x++) {
					if (nboard[x][y] == 0) continue;

					int nx = x + 1;
					while (nx < n) {
						if (nboard[nx][y] != 0) break;
						nx += 1;
					}

					if (nx >= n) {
						nboard[pos][y] = nboard[x][y];
						if (pos != x) nboard[x][y] = 0;
						break;
					}

					if (nboard[nx][y] == nboard[x][y]) {
						nboard[pos][y] = nboard[x][y] * 2;
						nboard[nx][y] = 0;
						if (pos != x) nboard[x][y] = 0;
						x = nx;
					}
					else {
						nboard[pos][y] = nboard[x][y];
						if (pos != x) nboard[x][y] = 0;
						x = nx - 1;
					}

					pos += 1;
				}
			}
		}

		dfs(nboard, cnt + 1);
	}
}

int main() {
	scanf("%d", &n);

	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &board[i][j]);
	}

	dfs(board, 0);
	printf("%d\n", max_value);

	return 0;
}