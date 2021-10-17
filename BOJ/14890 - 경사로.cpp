#include <vector>
#include <cstdio>

using namespace std;

int n, l, ans = 0;
vector<vector<int>> map;

void check_road(vector<int> road) {
	vector<int> visit(road.size(), 0);
	int cnt = 1;

	for (int i = 0; i < road.size() - 1; i++) {
		if (road[i] != road[i + 1]) {
			if (abs(road[i] - road[i + 1]) > 1) return;
			if (road[i] < road[i + 1] && cnt < l) return;

			cnt = 1;

			if (road[i] > road[i + 1]) {
				for (int j = i + 1; j < i + l; j++) {
					if (j + 1 >= n) return;
					if (road[j] != road[j + 1]) return;
				}

				i = i + l - 1;
				cnt = 0;
			}
		}
		else cnt += 1;
	}

	ans += 1;
}

int main() {
	scanf("%d %d", &n, &l);

	map.resize(2 * n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			map[j + n][i] = map[i][j];
		}
	}

	for (vector<int> road : map) check_road(road);
	printf("%d", ans);

	return 0;
}