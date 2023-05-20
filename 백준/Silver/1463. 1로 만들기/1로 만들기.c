#include <stdio.h>

int dp[1000001] = {0};

int main(void) {
    int n = 0, temp = 0;
    scanf("%d", &n);
    dp[1] = 0;
    dp[2] = dp[3] = 1;

    for (int i = 4; i <= n; i++) {
        temp = dp[i - 1] + 1;
        temp = i % 2 == 0 && dp[i - 1] >= dp[i / 2] ? dp[i / 2] + 1 : temp;
        temp = i % 3 == 0 && temp >= dp[i / 3] + 1 ? dp[i / 3] + 1 : temp;
        dp[i] = temp;
    }
    printf("%d", dp[n]);
}
