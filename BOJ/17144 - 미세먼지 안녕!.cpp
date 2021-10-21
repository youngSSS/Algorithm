#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

vector<vector<int>> room;
pair<int, int> u, d;
int r, c, t;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void expand() {
	vector<vector<int>> expanded_amt(r, vector<int>(c, 0));

	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++) {
			if (room[x][y] != 0 && room[x][y] != -1) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];

					if (0 <= nx && nx < r && 0 <= ny && ny < c && room[nx][ny] != -1) {
						cnt += 1;
						expanded_amt[nx][ny] += room[x][y] / 5;
					}
				}
				room[x][y] = room[x][y] - (room[x][y] / 5) * cnt;
			}
		}
	}

	for (int x = 0; x < r; x++) {
		for (int y = 0; y < c; y++)
			room[x][y] += expanded_amt[x][y];
	}
}

void clean() {
	vector<int> temps = { room[u.first][c - 1], room[0][c - 1], room[0][0], room[u.first][0] };

	for (int y = c - 1; y > 0; y--)
		room[u.first][y] = room[u.first][y - 1];
	for (int x = 0; x < u.first; x++)
		room[x][c - 1] = room[x + 1][c - 1];
	for (int y = 0; y < c - 1; y++)
		room[0][y] = room[0][y + 1];
	for (int x = u.first; x > 0; x--)
		room[x][0] = room[x - 1][0];

	room[u.first - 1][c - 1] = temps[0];
	room[0][c - 2] = temps[1];
	room[1][0] = temps[2];
	room[u.first][1] = temps[3];

	room[u.first][u.second] = -1;
	room[u.first][u.second + 1] = 0;

	temps = { room[d.first][c - 1], room[r - 1][c - 1], room[r - 1][0], room[d.first][0] };

	for (int y = c - 1; y > 0; y--)
		room[d.first][y] = room[d.first][y - 1];
	for (int x = r - 1; x > d.first; x--)
		room[x][c - 1] = room[x - 1][c - 1];
	for (int y = 0; y < c - 1; y++)
		room[r - 1][y] = room[r - 1][y + 1];
	for (int x = d.first; x < r - 1; x++)
		room[x][0] = room[x + 1][0];

	room[d.first + 1][c - 1] = temps[0];
	room[r - 1][c - 2] = temps[1];
	room[r - 2][0] = temps[2];
	room[d.first][1] = temps[3];

	room[d.first][d.second] = -1;
	room[d.first][d.second + 1] = 0;
}

int main() {
	scanf("%d %d %d", &r, &c, &t);

	room.resize(r, vector<int>(c));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			scanf("%d", &room[i][j]);
			if (room[i][j] == -1) {
				u = make_pair(i - 1, j);
				d = make_pair(i, j);
			}
		}
	}

	for (int i = 0; i < t; i++) {
		expand();
		clean();
	}

	int ans = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			ans += room[i][j];
	}

	printf("%d", ans + 2);

	return 0;
}