#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, pair<int, int>> map;

		for (int i = 0; i < nums.size(); i++) {
			if (map.find(nums[i]) != map.end()) return { map[nums[i]].second, i };
			map[target - nums[i]] = make_pair(1, i);
		}

		return {};
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> nums = { 3, 2, 4 };

	nums = solution->twoSum(nums, 6);
	for (auto num : nums) cout << num << " ";

	return 0;
}