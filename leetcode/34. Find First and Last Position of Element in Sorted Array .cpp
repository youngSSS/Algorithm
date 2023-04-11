#include <vector>

using namespace std;

class Solution {
 public:
	vector<int> searchRange(vector<int> nums, int target) {
		auto iter = find(nums.begin(), nums.end(), target);
		if (iter == nums.end()) return { -1, -1 };
		int start = iter - nums.begin();
		int end = start + 1;
		while (end < nums.size() && nums[start] == nums[end]) end++;
		return { start, end - 1 };
	}
};