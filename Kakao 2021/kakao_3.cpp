#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <cstdio>

using namespace std;

int string_to_int(string time) {
	int h = stoi(time.substr(0, 2));
	int m = stoi(time.substr(3));
	return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
	unordered_map<string, unordered_map<string, vector<int> > > map;
	vector<pair<int, int> > result;
	vector<int> answer;

	int base_time = fees[0];
	int base_cost = fees[1];
	int unit_time = fees[2];
	int unit_cost = fees[3];

	for (string record : records) {
		auto iter1 = find(record.begin(), record.end(), ' ');
		auto iter2 = find(iter1 + 1, record.end(), ' ');

		string time = record.substr(0, iter1 - record.begin());
		string car = record.substr(iter1 - record.begin() + 1, 4);
		string status = record.substr(iter2 - record.begin() + 1);

		map[car][status].push_back(string_to_int(time));
	}

	for (auto m : map) {
		string car = m.first;
		int cost = base_cost, time = 0;

		for (int i = 0; i < m.second["OUT"].size(); i++)
			time += (m.second["OUT"][i] - m.second["IN"][i]);

		if (m.second["IN"].size() > m.second["OUT"].size())
			time += (1439 - m.second["IN"][m.second["IN"].size() - 1]);

		if (base_time < time) {
			time -= base_time;
			if (time % unit_time == 0) cost += (time / unit_time) * unit_cost;
			else cost += (time / unit_time + 1) * unit_cost;
		}

		result.push_back(make_pair(stoi(car), cost));
	}

	sort(result.begin(), result.end());

	for (auto a : result)
		answer.push_back(a.second);

	return answer;
}

int main() {
	vector<int> answer = solution(
		{ 180, 5000, 10, 600 },
		{
			"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT",
			"07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN",
			"19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"
		}
	);
	for (auto ans : answer) cout << ans << " ";
	return 0;
}