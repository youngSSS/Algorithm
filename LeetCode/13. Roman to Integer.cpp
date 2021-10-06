#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
 public:
	int romanToInt(string s) {
		int answer = 0;
		unordered_map<string, int> map;

		map["I"] = 1;
		map["V"] = 5;
		map["X"] = 10;
		map["L"] = 50;
		map["C"] = 100;
		map["D"] = 500;
		map["M"] = 1000;

		map["IV"] = 4;
		map["IX"] = 9;
		map["XL"] = 40;
		map["XC"] = 90;
		map["CD"] = 400;
		map["CM"] = 900;

		for (int i = 0; i < s.size(); i++) {
			string now(1, s[i]);
			string next = s.substr(i, 2);

			if (map.find(next) != map.end()) {
				answer += map[next];
				if (now != next) i += 1;
			}
			else answer += map[now];
		}

		return answer;
	}
};

