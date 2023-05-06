#include <stdio.h>

#define MAX 1000

int sort(int *arr, int arrSize) {
    for (int i = 0; i < arrSize - 1; i++) {
        for (int j = 0; j < arrSize - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                arr[j] += arr[j + 1];
                arr[j + 1] = arr[j] - arr[j + 1];
                arr[j] -= arr[j + 1];
            }
        }
    }
}

int main(void) {
    int arr[MAX] = {0,};
    int n, num;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        arr[i] = num;
    }
    sort(arr, n);
    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}