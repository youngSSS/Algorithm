#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <set>

using namespace std;

class Solution {
 public:
	vector<string> generateParenthesis(int n) {
		vector<string> answer;
		dfs(n, 0, "", answer);
		return answer;
	}

	void dfs(int n, int open_cnt, string s, vector<string> & answer) {
		if (s.size() == n * 2) {
			if (open_cnt == 0) answer.push_back(s);
			return;
		}

		dfs(n, open_cnt + 1, s + "(", answer);
		if (open_cnt > 0) dfs(n, open_cnt - 1, s + ")", answer);
	}
};

int main() {
	Solution* solution = new Solution();
	solution->generateParenthesis(3);
	return 0;
}
