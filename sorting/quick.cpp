#include <vector>
#include <string>
#include <iostream>

using namespace std;

class QuickSort {
 public:
	int medianOfThree(vector<int>& list, int start, int end) {
		int cand[3] = { start, (start + end) / 2, end };

		if (list[cand[0]] > list[cand[1]]) swap(cand[0], cand[1]);
		if (list[cand[1]] > list[cand[2]]) swap(cand[1], cand[2]);
		if (list[cand[0]] > list[cand[1]]) swap(cand[0], cand[1]);

		return cand[1];
	}

	int partition(vector<int>& list, int start, int end) {
		int pivot, pIdx;
		int left, right;

		pIdx = medianOfThree(list, start, end);
		iter_swap(list.begin() + start, list.begin() + pIdx);

		pivot = list[start];
		left = start + 1;
		right = end;

		while (left <= right) {
			while (left <= end && list[left] <= pivot) left += 1;
			while (right > start && list[right] >= pivot) right -= 1;

			if (left > right) iter_swap(list.begin() + start, list.begin() + right);
			else iter_swap(list.begin() + left, list.begin() + right);
		}

		return right;
	}

	void quickSort(vector<int>& list, int start, int end) {
		if (start >= end) return;

		int pivotIdx = partition(list, start, end);
		quickSort(list, start, pivotIdx - 1);
		quickSort(list, pivotIdx + 1, end);
	}

};

int main() {
	vector<int> nums = { 5, 8, 143, 3, 9, 77, 1, 4, -5, 0, 20, 7, 231, 0 };

	QuickSort* solution = new QuickSort();
	solution->quickSort(nums, 0, nums.size() - 1);

	for (auto num : nums) cout << num << " ";
	cout << endl;

	return 0;
}