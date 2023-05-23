#include <stdio.h>

int main(void) {
    int a, b, c, result;
    int dp[21][21][21];
    for (int i = 0; i < 21; i++)
        for (int j = 0; j < 21; j++)
            for (int k = 0; k < 21; k++)
                dp[i][j][k] = i == 0 || j == 0 || k == 0 ? 1 : 0;

    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1) break;
        if (a <= 0 || b <= 0 || c <= 0)
            result = 1;
        else if (a > 20 || b > 20 || c > 20)
            result = 1048576;
        else {
            for (int i = 1; i <= a; i++) {
                for (int j = 1; j <= b; j++) {
                    for (int k = 1; k <= c; k++) {
                        if (i < j && j < k) dp[i][j][k] = dp[i][j][k - 1] + dp[i][j - 1][k - 1] - dp[i][j - 1][k];
                        else
                            dp[i][j][k] =
                                    dp[i - 1][j][k] + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1] -
                                    dp[i - 1][j - 1][k - 1];
                    }
                }
            }
            result = dp[a][b][c];
        }
        printf("w(%d, %d, %d) = %d\n", a, b, c, result);
    }
}
