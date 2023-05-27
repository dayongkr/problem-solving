#include <stdio.h>

#define MAX(a, b) a >= b ? a : b

int main(void) {
    int n, dp[501], max = 0, temp[501];
    scanf("%d", &n);
    scanf("%d", &dp[1]);
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) scanf("%d", &temp[j]);
        for (int j = i; j >= 1; j--) {
            if (j != 1) dp[j] = MAX(dp[j], dp[j - 1]);
            if (j == i) dp[j] = dp[j - 1];
            dp[j] += temp[j];
        }

    }
    for (int i = 1; i <= n; i++) if (dp[i] > max) max = dp[i];
    printf("%d", max);
    return 0;
}