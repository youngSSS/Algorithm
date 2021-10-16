#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int n, ans = 1e9;
vector<int> team;
vector<vector<int>> status;

int get_status(vector<int> t) {
	int sum = 0;
	for (int i = 0; i < t.size(); i++) {
		for (int j = i + 1; j < t.size(); j++) {
			sum += status[t[i]][t[j]] + status[t[j]][t[i]];
		}
	}
	return sum;
}

void make_team(int start, int cnt) {
	if (cnt == n / 2) {
		vector<int> a_team, b_team;
		for (int i = 0; i < n; i++) {
			if (team[i] == 1) a_team.push_back(i);
			else b_team.push_back(i);
		}

		int gap = abs(get_status(a_team) - get_status(b_team));
		if (gap < ans) ans = gap;

		return;
	}

	for (int i = start; i < n; i++) {
		team[i] = 1;
		make_team(i + 1, cnt + 1);
		team[i] = 0;
	}
}

int main() {
	scanf("%d", &n);

	status.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &status[i][j]);
	}

	team.resize(n, 0);
	make_team(0, 0);


	printf("%d", ans);

	return 0;
}