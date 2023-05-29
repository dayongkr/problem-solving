#include <stdio.h>

#define MOD % 1000000000

int main(void) {
    int n, dp[101][10], sum = 0;
    scanf("%d", &n);
    dp[1][0] = 0;
    for (int i = 1; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1] MOD; // 맨 뒤가 0인 것은 1에서 1 빼는 거 밖에 없음
        dp[i][9] = dp[i - 1][8] MOD; // 맨 뒤가 9인 것은 8에서 1 더하는 거 밖에 없음
        for (int j = 1; j < 9; j++)
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) MOD;
    }
    for (int i = 0; i < 10; i++) sum = (sum + dp[n][i]) MOD;
    printf("%d", sum MOD);
    return 0;
}