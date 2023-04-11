class Solution {
 public:
	int myAtoi(string s) {
		long long value = 0;
		int idx = 0, negative = 1;
		string nums = "0123456789";

		while (s[idx] == ' ') idx += 1;

		if (s[idx] == '+') idx += 1;
		else if (s[idx] == '-') {
			negative = -1;
			idx += 1;
		}

		while (idx < s.size() && nums.find(s[idx]) != string::npos) {
			value = value * 10 + s[idx] - '0';
			if (value * negative > pow(2, 31) - 1) return pow(2, 31) - 1;
			if (value * negative < -pow(2, 31)) return -pow(2, 31);
			idx += 1;
		}

		return value * negative;
	}
};