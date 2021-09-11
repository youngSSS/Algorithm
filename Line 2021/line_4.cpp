#include <vector>
#include <cmath>

using namespace std;

int get_prime(int n) {
	vector<int> is_prime(n + 1, 1);
	is_prime[0] = 0;
	is_prime[1] = 0;

	for (int i = 2; i <= sqrt(n); i++) {
		if (!is_prime[i]) continue;
		for (int j = i + i; j <= n; j += i) {
			is_prime[j] = 0;
		}
	}

	for (int i = 2; i < n + 1; i++) {
		if (is_prime[i] == 1) {
			if (n % i == 0) return i;
		}
	}
}

vector<int> answer;

void mix(vector<int> arr, int n) {
	int prime = get_prime(n);
	int len = n / prime;

	if (n == 1) {
		answer.push_back(arr[0]);
		return;
	}

	vector<vector<int>> div(prime);
	for (int i = 0; i < arr.size(); i++)
		div[i % prime].push_back(arr[i]);

	for (auto d : div) mix(d, len);
}

vector<int> solution(int n) {
	vector<int> arr;
	for (int i = 1; i <= n; i++) arr.push_back(i);
	mix(arr, n);

	return answer;
}

int main() {
	solution(13);
	return 0;
}