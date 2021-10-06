#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	double myPow(double x, int n) {
		double answer = 1;
		long p = n, cnt = 0;

		if (p < 0) p = -p;

		long adder = 1;
		double multiplier = x;
		while (cnt < p) {
			if (cnt + adder <= p) {
				if (cnt == 0) answer = x;
				else answer = answer * multiplier;
				cnt += adder;
				adder *= 2;
				multiplier = multiplier * multiplier;
			}
			else {
				adder = 1;
				multiplier = x;
			}
		}

		if (n < 0) return 1 / answer;
		return answer;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> nums = { 2, 3, 1, 1, 4 };

	cout.precision(5);
	cout << fixed << solution->myPow(0.999999999, -2147483648);

	return 0;
}