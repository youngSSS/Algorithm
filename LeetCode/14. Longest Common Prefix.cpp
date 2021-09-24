#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
 public:
	string longestCommonPrefix(vector<string>& strs) {
		unordered_map<string, int> map;
		vector<pair<int, string>> list = {{0, ""}};

		for (string& str : strs) {
			for (int i = 1; i <= str.size(); i++) {
				string prefix = str.substr(0, i);
				map[prefix] += 1;
			}
		}

		for (auto & item : map) {
			if (item.second == strs.size())
				list.push_back(make_pair(-item.first.size(), item.first));
		}
		sort(list.begin(), list.end());

		return list[0].second;
	}
};