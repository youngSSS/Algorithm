#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
	int maxSubArray(vector<int>& nums) {
		int ans = nums[0];
		int tmp = nums[0];

		for (int i = 1; i < nums.size(); i++) {
			tmp = max(nums[i], tmp + nums[i]);
			ans = max(ans, tmp);
		}

		return ans;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> vec = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

	solution->maxSubArray(vec);

	return 0;
}