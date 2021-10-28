#include <vector>
#include <iostream>

using namespace std;

int check_time(int n, vector<int>& times) {
	int timer = 1;

	while (true) {
		for (int& time : times) {
			if (timer % time == 0) {
				int cnt = 0;
				for (int& t : times)
					cnt += timer / t;
				if (cnt >= n) return timer;
				break;
			}
		}

		timer += 1;
	}
}

int main() {
	vector<int> times, answer;
	int c, n, m;

	cin >> c;

	for (int i = 0; i < c; i++) {
		cin >> n >> m;

		times.resize(m);
		for (int j = 0; j < m; j++)
			cin >> times[j];

		answer.push_back(check_time(n, times));
	}

	for (auto ans : answer)
		cout << ans << endl;

	return 0;
}
