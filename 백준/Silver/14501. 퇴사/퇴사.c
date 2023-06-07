#include <stdio.h>

int dp[16][2];

int main(void) {
    int n = 0, max = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &dp[i][1], &dp[i][0]);
        if (dp[i][1] + i - 1 > n) dp[i][0] = 0;
    }
    for (int i = n; i >= 1; i--) {
        int c = dp[i][1], max_c = 0;
        for (int j = i + c; j <= n; j++)
            if (dp[j][0] > max_c) max_c = dp[j][0];
        dp[i][0] += max_c;
        if (dp[i][0] > max) max = dp[i][0];
    }
    printf("%d\n", max);
    return 0;
}
