#include <stdio.h>

int main(void) {
    int n = 0;
    scanf("%d", &n);
    int dp[n + 1];
    for (int i = 0; i < n + 1; i++)dp[i] = 0;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
    printf("%d", dp[n] % 15746);
    return 0;
}
