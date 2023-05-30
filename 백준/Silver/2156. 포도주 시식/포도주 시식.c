#include <stdio.h>

#define MAX(a, b) (a > b ? a : b)

int main(void) {
    int n, dp[10001], nums[10001], max = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
    }
    dp[0] = 0;
    dp[1] = nums[1];
    dp[2] = nums[1] + nums[2];
    // 계단오르기와 다르게 건너 뛸 수 있음
    for (int i = 3; i <= n; i++) dp[i] = MAX(nums[i] + MAX(dp[i - 3] + nums[i - 1], dp[i - 2]), dp[i - 1]);
    printf("%d", dp[n]);
    return 0;
}