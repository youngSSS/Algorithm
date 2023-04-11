#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	int maxArea(vector<int>& height) {
		int start = 0;
		int end = height.size() - 1;
		int max = 0;

		while (end - start > 0) {
			int a = min(height[start], height[end]);
			int b = end - start;

			if (a * b > max) max = a * b;
			if (height[start] > height[end]) end -= 1;
			else start += 1;
		}

		return max;
	}
};