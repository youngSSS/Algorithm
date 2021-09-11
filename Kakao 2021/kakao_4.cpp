#include <vector>
#include <iostream>

using namespace std;

int max_score = 0;
vector<int> answer = { -1 };
vector<int> now_info(11);

void dfs(int idx, int rest, vector<int> info) {
	if (rest == 0) {
		int s1 = 0, s2 = 0;

		for (int i = 0; i < 11; i++) {
			if (now_info[i] > info[i]) s1 += 10 - i;
			else if (now_info[i] <= info[i] && info[i] != 0) s2 += 10 - i;
		}

		if (s1 - s2 > max_score) {
			max_score = s1 - s2;
			answer = now_info;
		}

		// 처음에 동점처리를 안함
		else if (s1 - s2 > 0 && s1 - s2 == max_score) {
			for (int i = 10; i >= 0; i--) {
				if (answer[i] < now_info[i]) {
					answer = now_info;
					break;
				}
				else if (answer[i] > now_info[i]) break;
			}
		}

		return;
	}

	if (idx == 11) return;

	for (int i = 0; i <= rest; i++) {
		now_info[idx] = i;
		dfs(idx + 1, rest - i, info);
		now_info[idx] = 0;
	}
}

vector<int> solution(int n, vector<int> info) {
	dfs(0, n, info);
	return answer;
}

int main() {
	vector<int> a = solution(5, { 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 });
	for (auto i : a) cout << i << " " ;
	// Answer: 0 2 2 0 1 0 0 0 0 0 0
	return 0;
}