#include <stdio.h>

#define MAX 300

int main(void) {
    int n = 0;
    int step[MAX] = {0,};
    int score[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &step[i]);
    }
    score[0] = step[0];
    score[1] = step[1] + step[0];
    score[2] = step[0] > step[1] ? step[0] : step[1];
    score[2] += step[2];
    for (int i = 3; i < n; i++) {
        score[i] = step[i];
        score[i] += score[i - 3] + step[i - 1] > score[i - 2] ? score[i - 3] + step[i - 1] : score[i - 2];
    }
    printf("%d", score[n - 1]);
}
