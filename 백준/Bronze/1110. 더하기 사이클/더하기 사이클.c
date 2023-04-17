#include <stdio.h>

int main() {
    int n, m, count = 1;
    scanf("%d", &n);
    m = (n % 10 + (int) n / 10) % 10 + (n % 10 * 10);
    while (m != n) {
        m = (m % 10 + (int) m / 10) % 10 + (m % 10 * 10);
        count++;
    }
    printf("%d", count);
    return 0;
}