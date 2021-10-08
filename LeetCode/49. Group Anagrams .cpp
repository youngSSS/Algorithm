#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> answer;
		unordered_map<string, vector<string>> map;
		for (string& str : strs) {
			string item = str;
			sort(item.begin(), item.end());
			map[item].push_back(str);
		}
		answer.reserve(map.size());
		for (auto& m : map) answer.push_back(m.second);
		return answer;
	}
};

int main() {
	Solution* solution = new Solution();
	vector<string> vec = { "eat", "tea", "tan", "ate", "nat", "bat" };

	solution->groupAnagrams(vec);

	return 0;
}