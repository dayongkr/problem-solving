#include <stdio.h>

int arr[10000];

void sort(int *p, int arrSize) {
    for (int i = 0; i < arrSize; i++) {
        for (int j = 0; j < arrSize - 1 - i; j++) {
            if (p[j] < p[j + 1]) {
                int tmp = p[j + 1];
                p[j + 1] = p[j];
                p[j] = tmp;
            }
        }
    }
}

int main(void) {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, n);
    printf("%d\n", arr[k - 1]);
}
