#include <vector>
#include <cstdio>

using namespace std;

int get_max(int n, vector<int>& terms, vector<int>& ins) {
	vector<int> dp(n + 1, 0);
	int ans = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (terms[i] + i > n) dp[i] = dp[i + 1];
		else dp[i] = max(dp[i + 1], ins[i] + dp[i + terms[i]]);
		ans = max(ans, dp[i]);
	}

	return ans;
}

int main() {
	int n;
	scanf("%d", &n);

	vector<int> terms(n), ins(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &terms[i], &ins[i]);

	printf("%d", get_max(n, terms, ins));

	return 0;
}