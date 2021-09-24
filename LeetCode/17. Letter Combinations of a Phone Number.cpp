#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <set>

using namespace std;

class Solution {
 public:
	unordered_map<char, string> map;
	vector<string> answer;

	vector<string> letterCombinations(string digits) {
		if (digits.empty()) return {};

		string alphabet = "abcdefghijklmnopqrstuvwxyz";
		int s = 0, cnt = 3;
		for (int i = 2; i < 10; i++) {
			if (s == 15 || s == 22) cnt += 1;
			if (s == 19) cnt -= 1;
			map[i + '0'] = alphabet.substr(s, cnt);
			s += cnt;
		}

		dfs(digits, "");

		return answer;
	}

	void dfs(string digits, const string& comb) {
		if (digits.empty()) {
			answer.push_back(comb);
			return;
		}

		string words = map[digits[0]];
		for (auto w : words) {
			dfs(digits.substr(1), comb + w);
		}
	}
};

int main() {
	Solution* solution = new Solution();
	solution->letterCombinations("8");
	return 0;
}
