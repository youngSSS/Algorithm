class Solution {
 public:
	int reverse(int x) {
		long long v = 0;

		while (x != 0) {
			v = v * 10 + x % 10;
			if (v > pow(2, 31) - 1 || v < -pow(2, 31)) return 0;
			x /= 10;
		}

		return v;
	}
};