#include <stdio.h>
#include <limits.h>

int k, n; // k = 이미 가지고 있는 랜선의 개수, n = 필요한 랜선의 개수
int rans[10000];

int check(long long length) {
    long long sum = 0;
    for (int i = 0; i < k; i++) {
        if (length <= rans[i]) sum += (long long) (rans[i] / length);
        if (sum >= n) return 1;
    }
    return 0;
}

int main(void) {
    scanf("%d %d", &k, &n);
    for (int i = 0; i < k; i++) scanf("%d", &rans[i]);

    long l = 0, r = INT_MAX, ans = 0;
    while (l <= r) {
        long mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    printf("%d", ans);
}

// 이분탐색
// last occurrence of 1
// 타겟 확인하는 함수는 n을 만족하는지 확인