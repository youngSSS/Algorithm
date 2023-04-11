#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <set>
#include <stack>

using namespace std;

class Solution {
 public:
	int longestValidParentheses(string s) {
		int max = 0;
		int l = 0, r = 0;
		for (char c : s) {
			if (c == '(') l += 1;
			else if (c == ')' && r != l) r += 1;
			else if (c == ')' && r == l) {
				r = 0;
				l = 0;
			}
			if (r == l && r > max) max = r;
		}
		r = 0;
		l = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			if (s[i] == ')') r += 1;
			else if (s[i] == '(' && r != l) l += 1;
			else if (s[i] == '(' && r == l) {
				r = 0;
				l = 0;
			}
			if (r == l && r > max) max = r;
		}

		return max * 2;
	}
};

int main() {
	Solution* solution = new Solution();
	cout << solution->longestValidParentheses("(()");
	return 0;
}
