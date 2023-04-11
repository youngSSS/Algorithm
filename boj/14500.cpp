#include <vector>
#include <unordered_map>
#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
int answer = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

vector<vector<int>> map;
vector<vector<int>> visit;
vector<pair<int, int>> s;

void dfs(int x, int y, int sum, int cnt) {
	if (cnt >= 4) {
		sum += map[x][y];
		if (sum > answer) answer = sum;
		return;
	}

	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < n && 0 <= ny && ny < m && visit[nx][ny] == 0)
			dfs(nx, ny, sum + map[x][y], cnt + 1);
	}

	if (cnt == 2) {
		for (int i = 0; i < 4; i++) {
			int nx1 = x + dx[i];
			int ny1 = y + dy[i];
			int nx2 = x + dx[(i + 1) % 4];
			int ny2 = y + dy[(i + 1) % 4];

			if ((0 <= nx1 && nx1 < n && 0 <= ny1 && ny1 < m) && (0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m)) {
				if (visit[nx1][ny1] == 0 && visit[nx2][ny2] == 0) {
					int temp_sum = sum + map[x][y] + map[nx1][ny1] + map[nx2][ny2];
					if (temp_sum > answer) answer = temp_sum;
				}
			}
		}
	}
	visit[x][y] = 0;
}

int main() {
	scanf("%d %d", &n, &m);

	map.resize(n, vector<int>(m));
	visit.resize(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			dfs(i, j, 0, 1);
	}

	printf("%d", answer);

	return 0;
}