#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
 public:
	int strStr(string haystack, string needle) {
		if (needle.empty()) return 0;
		auto result = haystack.find(needle);
		if (result == string::npos) return -1;
		return result;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> nums = { 2, 3, 1, 1, 4 };

	cout << solution->strStr("hello", "k");
//	for (auto num : nums) cout << num << " ";

	return 0;
}