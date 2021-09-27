class Solution {
 public:
	int firstMissingPositive(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		auto iter = find_if(nums.begin(), nums.end(), [](int a) {return a > 0;});
		if (iter == nums.end()) return 1;
		if (nums[iter - nums.begin()] != 1) return 1;
		int smallest = 1;
		for (int i = iter - nums.begin() + 1; i < nums.size(); i++) {
			if (smallest == nums[i]) continue;
			if (smallest + 1 == nums[i]) smallest += 1;
			else return smallest + 1;
		}
		return nums.back() + 1;
	}
};