#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
 public:
	int trap(vector<int>& height) {
		int answer = 0;
		int left = 0, right = height.size() - 1;
		int l_max = 0, r_max = 0;

		while (left < right) {
			if (l_max < height[left]) l_max = height[left];
			if (r_max < height[right]) r_max = height[right];

			if (l_max <= r_max) {
				answer += l_max - height[left];
				left += 1;
			}
			else {
				answer += r_max - height[right];
				right -= 1;
			}
		}

		return answer;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> nums = { 0,1,0,2,1,0,1,3,2,1,2,1 };

	cout << solution->trap(nums);
//	for (auto num : nums) cout << num << " ";

	return 0;
}