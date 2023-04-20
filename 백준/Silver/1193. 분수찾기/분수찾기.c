#include <stdio.h>

int main() {
    int n, i = 1, level = 1, numer = 0, denom = 0;
    scanf("%d", &n);
    while (i + level <= n) {
        i += level++;
    }
    if (level % 2 == 0) {
        numer = 1 + (n - i);
        denom = level - (n - i);
    } else {
        numer = level - (n - i);
        denom = 1 + (n - i);
    }
    printf("%d/%d", numer, denom);

}

// N = 10000 ^ 2인데 시간 제한 0.5 따라서 O(N)은 어려울 것 같고 O(logN)이하로 풀어야 할 것 같음
// 분모 + 분자 == level - 1
// 피라미드 형태로 보임
// 몇 층 몇 번째에 있는지 구하는 것이 중요해보임
