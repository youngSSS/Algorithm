#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <set>

using namespace std;

class Solution {
 public:
	vector<vector<int>> threeSum(vector<int> nums) {
		if (nums.size() < 3) return {};

		// CASE: No Positive
		sort(nums.begin(), nums.end(), greater<>());
		if (nums[0] <= 0) {
			if (nums[2] == 0) return {{ 0, 0, 0 }};
			else return {};
		}

		// CASE: No Negative
		sort(nums.begin(), nums.end());
		if (nums[0] >= 0) {
			if (nums[2] == 0) return {{ 0, 0, 0 }};
			else return {};
		}

		vector<vector<int>> answer;

		int firstPositive = find_if(nums.begin(), nums.end(), [](int a) { return a > 0; }) - nums.begin();
		for (int i = 0; i < firstPositive; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;

			if (nums[i] == 0) {
				if (i + 2 < firstPositive) answer.push_back({ 0, 0, 0 });
				break;
			}

			int midIdx = i + 1;
			int maxIdx = nums.size() - 1;

			while (midIdx < maxIdx) {
				int sum = nums[i] + nums[midIdx] + nums[maxIdx];

				if (sum > 0) maxIdx -= 1;
				else if (sum < 0) midIdx += 1;
				else {
					answer.push_back({ nums[i], nums[midIdx], nums[maxIdx] });

					midIdx += 1;
					maxIdx -= 1;
					while (midIdx < maxIdx && nums[midIdx - 1] == nums[midIdx]) midIdx += 1;
					while (midIdx < maxIdx && nums[maxIdx + 1] == nums[maxIdx]) maxIdx -= 1;
				}
			}
		}

		return answer;
	}
};

int main() {
	Solution* solution = new Solution();
	solution->threeSum({ 1, 2, -2, -1 });
	return 0;
}
