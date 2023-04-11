#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
 public:
	int jump(vector<int>& nums) {
		int answer = 0;
		int idx = nums.size() - 1;

		while (idx > 0) {
			int next_idx;
			for (int i = idx - 1; i >= 0; i--) {
				if (idx - i <= nums[i]) next_idx = i;
			}
			answer += 1;
			idx = next_idx;
		}

		return answer;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> nums =
		{ 5, 6, 4, 4, 6, 9, 4, 4, 7, 4, 4, 8, 2, 6, 8, 1, 5, 9, 6, 5, 2, 7, 9, 7, 9, 6, 9, 4, 1, 6, 8, 8, 4, 4, 2, 0, 3,
		  8, 5 };

	cout << solution->jump(nums);

	return 0;
}