#include <vector>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	vector<int> candidates(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &candidates[i]);

	int a, b;
	scanf("%d %d", &a, &b);

	long long answer = 0;
	for (int& count : candidates) {
		count -= a;
		answer += 1;

		if (count < 0) continue;

		if (count % b == 0) answer += count / b;
		else answer += count / b + 1;
	}

	printf("%lld\n", answer);

	return 0;
}