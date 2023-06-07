#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

void rec(int *res, int *arr, int n, int a, int last) {
    if (a == 6) {
        for (int i = 0; i < 6; i++) printf("%d ", res[i]);
        printf("\n");
        return;
    }
    for (int i = last; i < n; i++) {
        res[a] = arr[i];
        rec(res, arr, n, a + 1, i + 1);
    }
}

int main(void) {
    int n = 0;
    int arr[49];
    int res[6];
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        qsort(arr, n, sizeof(int), compare);
        rec(res, arr, n, 0, 0);
        printf("\n");
    }
}