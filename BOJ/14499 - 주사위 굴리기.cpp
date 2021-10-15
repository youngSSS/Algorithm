#include <vector>
#include <unordered_map>
#include <cstdio>
#include <iostream>

using namespace std;

int n, m, x, y, k;
unordered_map<char, int> dice;

void roll_dice(int cmd, vector<vector<int>>& map) {
	if (cmd == 1) {
		if (y + 1 >= m) return;

		y += 1;

		int temp = dice['r'];
		dice['r'] = dice['u'];
		dice['u'] = dice['l'];
		dice['l'] = dice['d'];
		dice['d'] = temp;
	}
	else if (cmd == 2) {
		if (y - 1 < 0) return;

		y -= 1;

		int temp = dice['l'];
		dice['l'] = dice['u'];
		dice['u'] = dice['r'];
		dice['r'] = dice['d'];
		dice['d'] = temp;
	}
	else if (cmd == 3) {
		if (x - 1 < 0) return;

		x -= 1;

		int temp = dice['f'];
		dice['f'] = dice['u'];
		dice['u'] = dice['b'];
		dice['b'] = dice['d'];
		dice['d'] = temp;
	}
	else if (cmd == 4) {
		if (x + 1 >= n) return;

		x += 1;

		int temp = dice['b'];
		dice['b'] = dice['u'];
		dice['u'] = dice['f'];
		dice['f'] = dice['d'];
		dice['d'] = temp;
	}

	if (map[x][y] == 0) map[x][y] = dice['d'];
	else {
		dice['d'] = map[x][y];
		map[x][y] = 0;
	}

	printf("%d\n", dice['u']);
}

int main() {
	scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

	vector<vector<int>> map(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			scanf("%d", &map[i][j]);
	}

	dice['u'] = 0;
	dice['d'] = 0;
	dice['r'] = 0;
	dice['l'] = 0;
	dice['f'] = 0;
	dice['b'] = 0;

	int cmd;
	for (int i = 0; i < k; i++) {
		scanf("%d", &cmd);
		roll_dice(cmd, map);
	}

	return 0;
}