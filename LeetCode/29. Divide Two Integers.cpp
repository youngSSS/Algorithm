#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
 public:
	int divide(int dividend, int divisor) {
		int answer = 0, flag = 1;
		long _dividend = dividend;
		long _divisor = divisor;

		if (dividend < 0) {
			flag *= -1;
			_dividend *= -1;
		}
		if (divisor < 0) {
			flag *= -1;
			_divisor *= -1;
		}

		bitset<32> d1(_dividend);
		bitset<32> d2(_divisor);

		cout << d1 << ", " << d2<<endl;
		cout << d1.to_ulong() << ", " << d2.to_ulong() << endl;

		if (_dividend < _divisor) return 0;
		else if (d1 == d2) return 1 * flag;

		if (d1 == 2147483648 && d2 == 1) {
			if (flag == -1) return -2147483648;
			else return 2147483647;
		}

		while (d1.to_ulong() > d2.to_ulong()) {
			d2 = d2 + 1;
			answer += 1;
		}
		if (d1 == d2) answer += 1;

		return answer * flag;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<int> nums = { 2, 3, 1, 1, 4 };

	cout << solution->divide(-2147483647, 2);

	return 0;
}