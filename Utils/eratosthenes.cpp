#include <math.h>

// 2 ~ n 사이의 소수를 구하는 함수
// "is_prime[idx] == 1" means idx is prime
int is_prime[n] = {1, };

void sieve_of_eratosthenes(int n) {
    for (int i = 2; i <= n; i++)
        is_prime[i] = 1;

    for (int i = 2; i <= sqrt(n); i++) {
        if (!is_prime[i]) continue;
        for (int j = i + i; j <= n; j += i) {
            is_prime[j] = 0;
        }
    }
}