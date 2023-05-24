#include <stdio.h>

int main(void) {
    long dp[101];
    int n, max = 5, num;
    dp[0] = dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;
    scanf("%d", &n);
    for (int _ = 0; _ < n; _++) {
        scanf("%d", &num);
        for (int i = max + 1; i <= num; i++) dp[i] = dp[i - 1] + dp[i - 5];
        if (num > max) max = num;
        printf("%ld\n", dp[num]);
    }
    return 0;
}
