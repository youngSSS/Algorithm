#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;
	int prize[7] = {6, 6, 5, 4, 3, 2, 1};

	sort(lottos.begin(), lottos.end(), greater<>());
	sort(win_nums.begin(), win_nums.end(), greater<>());

	int l_idx = 0, w_idx = 0;
	int cnt = 0, zero_cnt = 0;
	while (l_idx < 6 && w_idx < 6) {
		if (lottos[l_idx] == win_nums[w_idx]) {
			cnt += 1;
			l_idx += 1;
			w_idx += 1;
		}
		else if (lottos[l_idx] > win_nums[w_idx]) l_idx += 1;
		else w_idx += 1;
	}

	if (l_idx < 6 && lottos[l_idx] == 0) zero_cnt = 6 - l_idx;

	answer.push_back(prize[cnt + zero_cnt]);
	if (cnt == 0) answer.push_back(prize[0]);
	else answer.push_back(prize[cnt]);

	return answer;
}