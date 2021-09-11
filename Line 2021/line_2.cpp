#include <algorithm>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int check_issue(vector<int> days, int n, int k, int d_len) {
	int start = 0, end = n;
	int count = 0;

	while (end <= d_len) {
		int sum = 0;
		for (int i = start; i < end; i++) {
			if (days[i] < k) {
				sum = 0;
				break;
			}
			sum += days[i];
		}
		if (sum >= 2 * n * k) count += 1;
		start += 1;
		end += 1;
	}

	return count;
}

string solution(vector<string> research, int n, int k) {
	unordered_map<char, vector<int>> map;
	vector<pair<int, char>> ans_list;

	for (int i = 0; i < research.size(); i++) {
		for (char w : research[i]) {
			if (map.find(w) == map.end()) map[w] = vector<int>(30, 0);
			map[w][i] += 1;
		}
	}

	for (auto a : map) {
		char word = a.first;
		int count = check_issue(a.second, n, k, research.size());
		ans_list.push_back(make_pair(-count, word));
	}

	sort(ans_list.begin(), ans_list.end());

	string answer(1, ans_list[0].second);

	if (ans_list[0].first == 0) return "None";
	return answer;
}

int main() {
	cout << solution({ "abaaaa", "aaa", "abaaaaaa", "fzfffffffa" }, 2, 2);
	return 0;
}