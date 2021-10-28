#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;

int n, m, t;

unordered_map<int, int> elevator;
unordered_map<int, queue<pair<int, int>>> waiting;

int operate_elevator() {
	int temp_t = 0;
	int cnt = 0, max_cnt = 0;
	int floor = 1, adder = 1;
	int timer = 1;

	while (temp_t < t) {
		// Get off the elevator
		if (elevator[floor] > 0) {
			cnt -= elevator[floor];
			elevator[floor] = 0;
		}

		// Get on the elevator
		if (!waiting[floor].empty() && waiting[floor].front().first <= timer) {
			if (cnt == m) return timer;

			elevator[waiting[floor].front().second] += 1;
			waiting[floor].pop();
			cnt += 1;
			temp_t += 1;

			if (cnt > max_cnt) max_cnt = cnt;
		}

		// Move elevator to next floor
		if (n != 1) {
			floor += adder;

			if (floor > n) {
				floor = n - 1;
				adder = -1;
			}
			else if (floor < 1) {
				floor = 2;
				adder = 1;
			}
		}

		timer += 1;
	}

	return max_cnt - m;
}

int main() {
	int c;
	scanf("%d", &c);

	vector<int> answer(c);

	for (int i = 0; i < c; i++) {
		scanf("%d %d %d", &n, &m, &t);

		elevator.clear();
		waiting.clear();

		int temp_t = t;
		for (int j = 1; j <= temp_t; j++) {
			int start, dest;
			scanf("%d %d", &start, &dest);

			if (start != dest)
				waiting[start].push(make_pair(j, dest));
			else t -= 1;
		}

		answer[i] = operate_elevator();
	}

	for (int ans : answer)
		cout << ans << endl;

	return 0;
}
