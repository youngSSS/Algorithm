#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	int lengthOfLongestSubstring(string s) {
		int max_len = 0, len = 0;
		set<char> checker;
		unordered_map<char, int> map;

		for (int i = 0; i < s.size(); i++) {
			char c = s[i];
			if (checker.find(c) == checker.end()) {
				checker.insert(c);
				map[c] = i;
				len += 1;
			}
			else {
				checker.clear();
				i = map[c];
				if (max_len < len) max_len = len;
				len = 0;
			}
		}

		if (max_len < len) max_len = len;

		return max_len;
	}
};
