#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int n, m;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int ans = 1e9, temp = 0;

void dfs(int x, int y, vector<vector<int>>& map, vector<vector<int>>& visit) {
	visit[x][y] = 1;
	temp += 1;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (0 <= nx && nx < n && 0 <= ny && ny < m && map[nx][ny] != 1 && visit[nx][ny] == 0) {
			map[nx][ny] = 2;
			dfs(nx, ny, map, visit);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);

	vector<vector<int>> map(n, vector<int>(m));
	vector<pair<int, int>> blanks, viruses;
	int wall_cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 0) blanks.push_back(make_pair(i, j));
			else if (map[i][j] == 1) wall_cnt += 1;
			else if (map[i][j] == 2) viruses.push_back(make_pair(i, j));
		}
	}

	int b_size = blanks.size();
	for (int i = 0; i < b_size; i++) {
		map[blanks[i].first][blanks[i].second] = 1;

		for (int j = i + 1; j < b_size; j++) {
			map[blanks[j].first][blanks[j].second] = 1;

			for (int k = j + 1; k < b_size; k++) {
				map[blanks[k].first][blanks[k].second] = 1;

				vector<vector<int>> visit(n, vector<int>(m, 0));
				vector<vector<int>> t_map = map;
				temp = 0;

				for (auto & virus : viruses) {
					int x = virus.first;
					int y = virus.second;

					if (visit[x][y] == 0)
						dfs(x, y, t_map, visit);
				}

				if (temp < ans) ans = temp;

				map[blanks[k].first][blanks[k].second] = 0;
			}

			map[blanks[j].first][blanks[j].second] = 0;
		}

		map[blanks[i].first][blanks[i].second] = 0;
	}

	printf("%d", m * n - ans - wall_cnt - 3);

	return 0;
}