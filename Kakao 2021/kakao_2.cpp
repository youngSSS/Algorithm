#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long reverse(long long digit)
{
	long long reverse = 0;
	while (digit != 0)
	{
		reverse = digit % 10 + reverse * 10;
		digit /= 10;
	}
	return reverse;
}

long long is_prime(long long digit)
{
	if (digit <= 1)
	{
		return 0;
	}
	for (long long  i = 2; i * i <= digit; i++)
	{
		if (digit % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

int solution(int n, int k)
{
	int answer = 0;

	long long now_digit = 0;
	while (n != 0)
	{
		if (n % k == 0)
		{
			answer += is_prime(reverse(now_digit));
			now_digit = 0;
		}
		now_digit = now_digit * 10 + n % k;
		n /= k;
	}
	answer += is_prime(reverse(now_digit));
	return answer;
}