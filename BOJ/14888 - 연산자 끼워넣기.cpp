#include <vector>
#include <cstdio>

using namespace std;

int n, min_ans = 1e9, max_ans = -1e9;
vector<int> nums, ops(4);

void calculate(int value, int ops_cnt) {
	if (ops_cnt == n - 1) {
		if (value < min_ans) min_ans = value;
		if (value > max_ans) max_ans = value;
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (ops[i] != 0) {
			ops[i] -= 1;
			ops_cnt += 1;
			if (i == 0) calculate(value + nums[ops_cnt], ops_cnt);
			else if (i == 1) calculate(value - nums[ops_cnt], ops_cnt);
			else if (i == 2) calculate(value * nums[ops_cnt], ops_cnt);
			else if (i == 3) calculate(value / nums[ops_cnt], ops_cnt);
			ops_cnt -= 1;
			ops[i] += 1;
		}
	}
}

int main() {
	scanf("%d", &n);

	nums.resize(n);
	for (int i = 0; i < n; i++) scanf("%d", &nums[i]);
	for (int i = 0; i < 4; i++)	scanf("%d", &ops[i]);

	calculate(nums[0], 0);

	printf("%d\n%d", max_ans, min_ans);

	return 0;
}