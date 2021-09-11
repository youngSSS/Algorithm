#include <vector>
#include <iostream>

using namespace std;

int ans = 0;
vector<int> students;

void dfs(int now, int cnt, int limit) {
	if (students[now] == 1) cnt += 1;

	if (cnt > limit) return;
	if (cnt == limit) ans += 1;

	if (now < students.size() - 1)
		dfs(now + 1, cnt, limit);
}

int solution(vector<int> student, int k) {
	students = student;

	for (int i = 0; i < students.size(); i++)
		dfs(i, 0, k);

	return ans;
}

int main() {
	cout << solution({ 1, 1, 1, 1, 1 }, 2);
	return 0;
}