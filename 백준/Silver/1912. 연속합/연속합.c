#include <stdio.h>

int main(void) {
    int n, max;
    scanf("%d", &n);
    int dp[n];
    for (int i = 0; i < n; i++) scanf("%d", &dp[i]);

    max = dp[0];
    for (int i = 1; i < n; i++) {
        if (dp[i - 1] + dp[i] > dp[i]) dp[i] = dp[i] + dp[i - 1];
        if (dp[i] > max) max = dp[i];
    }
    printf("%d", max);
}
