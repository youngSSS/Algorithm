#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <string>
#include <iostream>

using namespace std;

int ans = 1e9;

void check_balance(string s) {
	if (s.empty()) return;

	set<char> checker;
	for (char c : s) checker.insert(c);

	for (char c : checker) {
		if ('a' <= c && c <= 'z') {
			if (checker.find(toupper(c)) == checker.end())
				return;
		}
		else {
			if (checker.find(tolower(c)) == checker.end())
				return;
		}
	}

	if (ans > s.size()) ans = s.size();
}

int solution(string& S) {
	set<char> checker;
	vector<int> idx;

	for (char c : S)
		checker.insert(c);

	for (int i = 0; i < S.size(); i++) {
		char c = S[i];

		if ('a' <= c && c <= 'z') {
			if (checker.find(toupper(c)) == checker.end())
				idx.push_back(i);
		}
		else {
			if (checker.find(tolower(c)) == checker.end())
				idx.push_back(i);
		}
	}

	if (idx.empty()) check_balance(S);
	else {
		int start, end;
		for (int i = 0; i < idx.size(); i++) {
			if (i == 0) start = 0;
			else start = idx[i - 1] + 1;
			end = idx[i];
			check_balance(S.substr(start, end - start));
		}
		check_balance(S.substr(idx.back() + 1));
	}

	if (ans == 1e9) return -1;
	else return ans;
}

int main() {
	string s = "AcCbaBz";
	cout << solution(s);
	return 0;
}