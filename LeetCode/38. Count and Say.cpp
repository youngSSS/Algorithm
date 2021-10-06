#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
 public:
	string countAndSay(int n) {
		string answer = "1";

		for (int i = 1; i < n; i++)
			answer = analyze(answer);

		return answer;
	}

	string analyze(string num) {
		string ret_val;
		int idx = 0;

		while (idx < num.size()) {
			int n = num[idx++] - '0';

			int cnt = 1;
			while (idx < num.size() && n == num[idx] - '0') {
				idx++;
				cnt++;
			}

			ret_val += to_string(cnt) + to_string(n);
		}

		return ret_val;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> nums = { 2, 3, 1, 1, 4 };

	cout << solution->countAndSay(4);

	return 0;
}