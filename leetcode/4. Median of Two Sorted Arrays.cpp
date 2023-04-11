#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len = nums1.size() + nums2.size();
		int idx1 = 0, idx2 = 0;
		int v1, v2;

		if (nums1.empty()) {
			int size = nums2.size();
			if (size % 2 == 1) return (float) nums2[size / 2];
			else return (float) (nums2[size / 2 - 1] + nums2[size / 2]) / 2;
		}

		if (nums2.empty()) {
			int size = nums1.size();
			if (size % 2 == 1) return (float) nums1[size / 2];
			else return (float) (nums1[size / 2 - 1] + nums1[size / 2]) / 2;
		}

		while (idx1 + idx2 < len / 2 + 1) {
			int value;

			if (idx1 >= nums1.size()) {
				value = nums2[idx2];
				idx2 += 1;
			}
			else if (idx2 >= nums2.size()) {
				value = nums1[idx1];
				idx1 += 1;
			}
			else {
				if (nums1[idx1] < nums2[idx2]) {
					value = nums1[idx1];
					idx1 += 1;
				}
				else {
					value = nums2[idx2];
					idx2 += 1;
				}
			}

			if (idx1 + idx2 == len / 2 && len % 2 == 0) v1 = value;
			else if (idx1 + idx2 == len / 2 + 1 && len % 2 == 0) v2 = value;
			else if (idx1 + idx2 == len / 2 + 1 && len % 2 == 1) v1 = value;
		}

		if (len % 2 == 0) return (float) (v1 + v2) / 2;
		else return v1;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> a = {3};
	vector<int> b = {-2, -1};
	cout << solution->findMedianSortedArrays(a, b);
}