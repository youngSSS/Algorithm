#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
 public:
	void partition(vector<int>& nums, int start, int end) {
		if (start >= end) return;

		int mid = (start + end) / 2;
		partition(nums, start, mid);
		partition(nums, mid + 1, end);
		mergeSort(nums, start, mid, end);
	}

	void mergeSort(vector<int>& nums, int start, int mid, int end) {
		vector<int> sortedList(end - start + 1);

		int idx1 = start;
		int idx2 = mid + 1;
		int idx = 0;

		while (idx1 <= mid && idx2 <= end) {
			if (nums[idx1] <= nums[idx2]) sortedList[idx++] = nums[idx1++];
			else sortedList[idx++] = nums[idx2++];
		}

		while (idx1 <= mid) sortedList[idx++] = nums[idx1++];
		while (idx2 <= end) sortedList[idx++] = nums[idx2++];

		for (int i = start; i <= end; i++)
			nums[i] = sortedList[i - start];
	}

	vector<int> sortArray(vector<int>& nums) {
		partition(nums, 0, nums.size() - 1);
		return nums;
	}
};

int main() {
	vector<int> nums = { 5, 1, 0, 24, -42, 8, 13, 3, 90, -13 };

	auto* solution = new Solution();
	solution->sortArray(nums);

	for (auto a : nums) cout << a << " ";

	return 0;
}