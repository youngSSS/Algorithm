#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
	bool canJump(vector<int>& nums) {
		int max_idx = 0;

		for (int i = 0; i < nums.size() - 1; i++) {
			int num = nums[i];
			if (num == 0 && max_idx < i + 1) return false;
			if (num != 0 && i + num > max_idx)
				max_idx = i + num;
		}

		return true;
	}
};