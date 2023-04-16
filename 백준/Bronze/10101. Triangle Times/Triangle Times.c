#include <stdio.h>

int main() {
    int arr[3] = {0,};
    int sum = 0, angle = 60, same = 0;
    for (int i = 0; i < 3; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
        angle ^= arr[i];
    }
    if (sum == 180) {
        if (!angle)
            printf("Equilateral\n");
        else {
            for (int i = 0; i < 3; i++) {
                for (int j = i + 1; j < 3; j++) {
                    if (arr[i] == arr[j]) {
                        same = 1;
                    }
                }
            }
            if (same)
                printf("Isosceles\n");
            else
                printf("Scalene\n");
        }
    } else
        printf("Error\n");

    return 0;
}