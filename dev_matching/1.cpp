#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> registered_list, string new_id) {
	unordered_map<string, int> map;

	for (string id : registered_list)
		map[id] = 1;

	while (true) {
		if (map.find(new_id) == map.end()) break;

		int idx;
		for (idx = 0; idx < new_id.size(); idx++) {
			if (isdigit(new_id[idx])) break;
		}

		int n;

		if (idx == new_id.size()) n = 0;
		else n = stoi(new_id.substr(idx));

		n += 1;

		new_id = new_id.substr(0, idx) + to_string(n);
	}

	return new_id;
}

int main() {

	return 0;
}
