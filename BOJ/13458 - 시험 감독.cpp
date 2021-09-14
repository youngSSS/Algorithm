#include <stdio.h>

int N, B, C;
int A[1000001] = {0, };

long long calculation();

int main() {
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        scanf("%d", &A[i]);

    scanf("%d %d", &B, &C);

    printf("%lld", calculation());

    return 0;
}

long long calculation() {
    long long cnt = 0;

    for (int i = 1; i <= N; i++) {
        A[i] -= B;
        cnt++;

        if (A[i] > 0) {
            if (A[i] % C != 0)
                cnt += (A[i] / C) + 1;
            else
                cnt += A[i] / C;
        }
    }

    return cnt;
}