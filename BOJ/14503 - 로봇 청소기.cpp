#include <vector>
#include <unordered_map>
#include <cstdio>
#include <iostream>

using namespace std;

int n, m, ans = 0;
unordered_map<int, pair<pair<int, int>, pair<int, int>>> dir;
vector<vector<int>> map, visit;

void do_clean(int x, int y, int d) {
	visit[x][y] = 1;
	ans += 1;

	int cnt;
	for (cnt = 0; cnt < 4; cnt++) {
		d -= 1;
		if (d == -1) d = 3;

		int nx = x + dir[d].first.first;
		int ny = y + dir[d].first.second;

		if (map[nx][ny] == 0 && visit[nx][ny] == 0) {
			do_clean(nx, ny, d);
			break;
		}
	}

	if (cnt == 4) {
		int nx = x + dir[d].second.first;
		int ny = y + dir[d].second.second;

		if (map[nx][ny] == 0) {
			ans -= 1;
			do_clean(nx, ny, d);
		}
	}
}

int main() {
	int x, y, d;
	scanf("%d %d", &n, &m);
	scanf("%d %d %d", &x, &y, &d);

	map.resize(n, vector<int>(m));
	visit.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	}

	dir[0] = {{ -1, 0 }, { 1, 0 }};
	dir[1] = {{ 0, 1 }, { 0, -1 }};
	dir[2] = {{ 1, 0 }, { -1, 0 }};
	dir[3] = {{ 0, -1 }, { 0, 1 }};

	do_clean(x, y, d);

	printf("%d", ans);

	return 0;
}