#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<pair<int, pair<int, int>>> list;
	for (int i = 0; i < n; i++) {
		int num, a, b, c;
		scanf("%d %d %d %d", &num, &a, &b, &c);

		list.push_back(make_pair(a * b * c, make_pair(a + b + c, num)));
	}
	sort(list.begin(), list.end());

	for (int i = 0; i < 3; i++)
		printf("%d ", list[i].second.second);

	return 0;
}
