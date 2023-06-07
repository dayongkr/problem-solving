#include <stdio.h>

int dp[1001];

int main(void) {
    int n = 0;
    scanf("%d", &n);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
    printf("%d", dp[n] % 10007);
}
