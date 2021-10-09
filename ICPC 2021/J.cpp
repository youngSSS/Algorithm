#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <stdio.h>

using namespace std;

vector<vector<int>> map;
int n, m;
int answer = 0;

void checker(int x1, int y1, int x2, int y2) {
	int x_dist = 0;
	int y_dist = 0;

	while (x2 + x_dist < n) {

		while (y2 + y_dist < m) {

			int sum = 0;
			for (int x = x1 + x_dist; x <= x2 + x_dist; x++) {
				for (int y = y1 + y_dist; y <= y2 + y_dist; y++)
					sum += map[x][y];
			}
			if (sum == 10) answer += 1;

			y_dist += 1;
		}

		y_dist = 0;
		x_dist += 1;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	map.resize(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	}

	for (int i = 0; i < 10; i++) {
		int j = 0;
		while ((i + 1) * (j + 1) <= 10) {
			checker(0, 0, i, j);
			j += 1;
		}
	}

	printf("%d", answer);

	return 0;
}
