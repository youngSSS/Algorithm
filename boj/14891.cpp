#include <vector>
#include <iostream>

#define L 6
#define R 2

using namespace std;

vector<vector<int>> gears(4);

void rotate_gear(int idx, int dir, vector<int>& visit) {
	bool l_flag = false, r_flag = false;

	visit[idx] = 1;

	if (idx > 0) l_flag = gears[idx][L] != gears[idx - 1][R];
	if (idx < 3) r_flag = gears[idx][R] != gears[idx + 1][L];

	if (dir == 1) {
		int temp = gears[idx][7];
		for (int i = 7; i > 0; i--)
			gears[idx][i] = gears[idx][i - 1];
		gears[idx][0] = temp;
	}
	else {
		int temp = gears[idx][0];
		for (int i = 0; i < 7; i++)
			gears[idx][i] = gears[idx][i + 1];
		gears[idx][7] = temp;
	}

	if (l_flag && visit[idx - 1] == 0)
		rotate_gear(idx - 1, dir * -1, visit);

	if (r_flag && visit[idx + 1] == 0)
		rotate_gear(idx + 1, dir * -1, visit);
}

int main() {
	for (int i = 0; i < 4; i++) {
		string gear;
		cin >> gear;
		for (char g : gear) gears[i].push_back(g - '0');
	}

	int k;
	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		int idx, dir;
		scanf("%d %d", &idx, &dir);

		vector<int> visit(4, 0);
		rotate_gear(idx - 1, dir, visit);
	}

	int ans = 0, score = 1;
	for (auto gear : gears) {
		if (gear[0] == 1) ans += score;
		score *= 2;
	}

	printf("%d", ans);

	return 0;
}