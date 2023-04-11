#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <set>

using namespace std;

class Solution {
 public:
	unordered_map<char, int> map;
	vector<char> mru;

	bool isValid(string s) {
		bool answer = false;
		dfs(s, answer);
		return answer;
	}

	void dfs(string s, bool& answer) {
		if (s.empty() && mru.empty()) answer = true;
		if (s.empty()) return;

		char c = s[0];
		if (c == '(' || c == '{' || c == '[') {
			map[c] += 1;
			mru.push_back(c);
		}
		else {
			if (c == ')') c = '(';
			else if (c == '}') c = '{';
			else if (c == ']') c = '[';

			if (map[c] == 0 || mru.back() != c) return;

			map[c] -= 1;
			mru.pop_back();
		}

		dfs(s.substr(1), answer);
	}
};

int main() {
	Solution* solution = new Solution();
	cout << solution->isValid("()[]{}");
	return 0;
}
