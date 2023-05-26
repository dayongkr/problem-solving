#include <stdio.h>

#define MIN(a, b)  a >= b ? b : a

int main(void) {
    int n, dp[1001][3];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d %d %d", &dp[i][0], &dp[i][1], &dp[i][2]);
    for (int i = 2; i <= n; i++) {
        dp[i][0] += MIN(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] += MIN(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] += MIN(dp[i - 1][0], dp[i - 1][1]);
    }
    printf("%d", MIN(dp[n][0], (MIN(dp[n][1], dp[n][2]))));
}
