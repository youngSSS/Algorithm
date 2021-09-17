#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	unordered_map<string, unordered_map<string, int>> map;

	bool isMatch(string s, string p) {
		int s_idx = 0;
		int s_size = s.size();
		int p_size = p.size();

		cout << s << ", " << p << endl;

		if (p.empty() && s.empty()) return true;

		for (int i = 0; i < p_size; i++) {
			int now = i;
			int next = i + 1 >= p_size ? i : i + 1;

			if (p[next] == '*') {
				if (p[now] == '.') {
					for (int j = s_idx; j <= s_size; j++) {
						if (map[s.substr(j)][p.substr(next + 1)] == 0) {
							if (isMatch(s.substr(j), p.substr(next + 1))) return true;
							else map[s.substr(j)][p.substr(next + 1)] = 1;
						}
					}
				}
				else {
					if (map[s.substr(s_idx)][p.substr(next + 1)] == 0) {
						if (isMatch(s.substr(s_idx), p.substr(next + 1))) return true;
						else map[s.substr(s_idx)][p.substr(next + 1)] = 1;
					}

					for (int j = s_idx; j < s_size; j++) {
						cout << "String: " << s.substr(j + 1) << ", Pattern: " << p.substr(next + 1) << endl;
						if (s[j] == p[now]) {
							if (map[s.substr(j + 1)][p.substr(next + 1)] == 0) {
								if (isMatch(s.substr(j + 1), p.substr(next + 1))) return true;
								else map[s.substr(j + 1)][p.substr(next + 1)] = 1;
							}
						}
						else break;
					}

				}
				return false;
			}

			else {
				if (s_idx >= s_size) return false;
				if (s[s_idx] == p[now] || p[now] == '.') s_idx += 1;
				else return false;
			}
		}

		return s_idx >= s_size;
	}
};

int main() {
	Solution* solution = new Solution();
	cout << solution->isMatch("aab",
		"c*a*b");
	return 0;
}