#include <stdio.h>

int devisor[100000] = {0,};

int main() {
    int n, sum = 1, count = 1;
    while (1) {
        sum = 1;
        count = 1;
        devisor[0] = 1;
        scanf("%d", &n);
        if (n == -1) {
            break;
        }
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                sum += i;
                devisor[count++] = i;
            }
        }
        if (sum == n) {
            printf("%d = 1", n);
            for (int j = 1; j < count; j++) {
                printf(" + %d", devisor[j]);
            }
        }
        if (sum > n) {
            printf("%d is NOT perfect.", n);
        }
        if (sum < n) {
            printf("%d is NOT perfect.", n);
        }
        printf("\n");
    }
}

// 자기 자신을 제외한 양수인 소수의 합으로 나타내지면 perfect라고 한다.
// n은 100,000, 시간 제한은 2초이므로 O(N) 시간 복잡도가 맥스인 것 같다.
// 자기 자신을 제외한 모든 소수의 합!