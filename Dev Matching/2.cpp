#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> calendar;
int max_len = 0;

void get_length() {
	int sum = 0;
	for (int i = 0; i < 30; i++) {
		if (calendar[i] == 0) {
			if (sum > max_len) max_len = sum;
			sum = 0;
		}
		else sum += 1;
	}
	if (sum > max_len) max_len = sum;
}

void use_leave(int start, int cnt) {
	if (cnt == 0) {
		get_length();
		return;
	}

	for (int i = start; i < 30; i++) {
		if (calendar[i] == 0) {
			calendar[i] = 1;
			use_leave(i + 1, cnt - 1);
			calendar[i] = 0;
		}
	}
}

int solution(int leave, string day, vector<int> holidays) {
	int answer = -1;

	int base = 0;
	if (day == "MON") base = 0;
	else if (day == "TUE") base = 1;
	else if (day == "WED") base = 2;
	else if (day == "THU") base = 3;
	else if (day == "FRI") base = 4;
	else if (day == "SAT") base = 5;
	else if (day == "SUN") base = 6;

	int cnt = 0;
	calendar.resize(30, 0);
	for (int i = 0; i < 30; i++) {
		if ((i + base + 2) % 7 == 0 || (i + base + 1) % 7 == 0) {
			calendar[i] = 1;
			cnt += 1;
		}
	}

	if (cnt + leave >= 30) return 30;

	for (int h : holidays) calendar[h - 1] = 1;

	use_leave(0, leave);

	return max_len;
}

int main() {

	cout << solution(4, "FRI",{6, 21, 23, 27, 28} );

	return 0;
}
