#include <stdio.h>
#include <math.h>

int n, k, max = 0, arr[3], num;

void rec(int s) {
    if (num > n) return;
    if (num > max) max = num;
    for (int i = 0; i < k; i++) {
        num += arr[i] * pow(10, s);
        rec(s + 1);
        num -= arr[i] * pow(10, s);
    }
}

int main(void) {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < k; i++) scanf("%d", &arr[i]);
    rec(0);
    printf("%d", max);
}