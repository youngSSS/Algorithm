#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> lines(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &lines[i]);

	unordered_map<int, int> tmp;
	unordered_map<int, unordered_map<int, int>> map;
	for (int i = n - 1; i >= 0; i--) {
		tmp[lines[i]] += 1;
		map[i] = tmp;
	}

	for (int i = 0; i < m; i++) {
		int s, e, winner = -1;
		scanf("%d %d", &s, &e);
		s -= 1;
		e -= 1;

		int max = 0;
		if (e == n - 1) {
			for (auto item : map[s]) {
				if (item.second > max) {
					max = item.second;
					winner = item.first;
				}
				else if (item.second == max) {
					if (item.first > winner) winner = item.first;
				}
			}
		}
		else {
			for (auto item : map[s]) {
				int gap = item.second - map[e][item.first];
				if (gap > max) {
					max = gap;
					winner = item.first;
				}
				else if (gap == max) {
					if (item.first > winner) winner = item.first;
				}
				if (gap > max) {
					max = gap;
					winner = item.first;
				}
				else if (gap == max) {
					if (item.first > winner) winner = item.first;
				}
			}
		}

		printf("%d\n", winner);
	}

	return 0;
}
