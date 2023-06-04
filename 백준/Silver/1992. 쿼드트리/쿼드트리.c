#include <stdio.h>
#include <string.h>

int arr[64][64];


void rec(int x, int y, int n) {
    int flag = 0;
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (arr[x][y] != arr[i][j]) {
                flag = 1;
                break;
            }
        }
        if (flag) break;
    }
    if (flag) {
        printf("(");
        rec(x, y, n / 2);
        rec(x, y + n / 2, n / 2);
        rec(x + n / 2, y, n / 2);
        rec(x + n / 2, y + n / 2, n / 2);
        printf(")");
    } else
        printf("%d", arr[x][y]);

}

int main(void) {
    int n;
    char temp[65];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        for (int j = 0; j < strlen(temp); j++) {
            arr[i][j] = temp[j] - '0';
        }
    }
    rec(0, 0, n);
    return 0;
}
