#include <stdio.h>

int n, m; // n: 나무의 수, m: 원하는 나무의 길이
int tree[1000000];

int check(int length) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (tree[i] > length) sum += tree[i] - length;
        if (sum >= m) return 1;
    }
    return 0;
}


int main(void) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &tree[i]);
    int l = 0, r = 2000000000, ans;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    printf("%d", ans);
}
