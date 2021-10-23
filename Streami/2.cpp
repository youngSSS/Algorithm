#include <vector>
#include <string>

using namespace std;

int solution(string &S) {
	int value = 0, ans = 0;

	int cnt = 1;
	for (int i = S.size() - 1; i >= 0; i--) {
		value += (S[i] - '0') * cnt;
		cnt *= 2;
	}

	while (value != 0) {
		if (value % 2 == 0) value /= 2;
		else value -= 1;
		ans += 1;

		if (ans >= 400000) return 799999;
	}

	return ans;
}

int main() {
	string s = "";
	cout << solution(s);
	return 0;
}