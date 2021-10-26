#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
 public:
	vector<int> heap;
	int heapCnt;

	void heapInsert(int num) {
		heapCnt += 1;
		heap[heapCnt] = num;

		int parent = heapCnt / 2;
		int child = heapCnt;

		while (child > 1 && heap[child] < heap[parent]) {
			iter_swap(heap.begin() + parent, heap.begin() + child);
			child = parent;
			parent /= 2;
		}
	}

	int heapDelete() {
		int value = heap[1];

		iter_swap(heap.begin() + 1, heap.begin() + heapCnt);
		heapCnt -= 1;
		heapfify(1);

		return value;
	}

	void heapfify(int parent) {
		int child = parent * 2;

		if (child > heapCnt) return;

		if (child + 1 <= heapCnt && heap[child] > heap[child + 1])
			child += 1;

		if (heap[parent] > heap[child]) {
			iter_swap(heap.begin() + parent, heap.begin() + child);
			heapfify(child);
		}
	}

	void buildHeap(vector<int>& nums) {
		heapCnt = heap.size();

		for (int i = 0; i < nums.size(); i++)
			heap[i + 1] = nums[i];

		for (int i = heapCnt / 2; i > 0; i--)
			heapfify(i);
	}

	vector<int> heapSort(vector<int>& nums) {
		heap.resize(nums.size() + 1);
		heapCnt = 0;

		// Solution 1
//		for (int num : nums) heapInsert(num);
//		for (int& num : nums) num = heapDelete();

		// Solution 2
		buildHeap(nums);
		for (int& num : nums) num = heapDelete();

		return nums;
	}
};

int main() {
	vector<int> nums = { 3, 7, 14, 11, 16, 7, 0, 6 };

	auto* solution = new Solution();
	solution->heapSort(nums);

	for (auto a : nums) cout << a << " ";

	return 0;
}