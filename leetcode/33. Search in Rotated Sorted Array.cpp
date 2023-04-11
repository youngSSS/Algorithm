#include <vector>

using namespace std;

class Solution {
 public:
	int search(vector<int>& nums, int target) {
		auto iter = find(nums.begin(), nums.end(), target);
		if (iter == nums.end()) return -1;
		else return iter - nums.begin();
	}
};