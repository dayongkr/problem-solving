#include <stdio.h>

#define MIN(a, b)  a >= b ? b : a

int main(void) {
    int n, dp[3], r, g, b;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &r, &g, &b);
        if (i != 1) {
            r += MIN(dp[1], dp[2]);
            g += MIN(dp[0], dp[2]);
            b += MIN(dp[0], dp[1]);
        }
        dp[0] = r;
        dp[1] = g;
        dp[2] = b;
    }
    printf("%d", MIN(dp[0], (MIN(dp[1], dp[2]))));
}
