#include <stdio.h>

int N, ans = 0;
int term[1000] = {0, };
int price[1000] = {0, };
int dp[1000] = {0, };

void DP();
int max(int a, int b) {
    if (a >= b) return a;
    else return b;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d %d", &term[i], &price[i]);

    DP();

    return 0;
}

void DP() {
    for (int i = N; i > 0; i--) {
        if (term[i] + i > N + 1) dp[i] = dp[i + 1];
        else dp[i] = max(dp[i + 1], price[i] + dp[i + term[i]]);
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
}