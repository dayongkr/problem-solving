#include <stdio.h>
#include <limits.h>

int n, m, b;
int arr[500][500];
int result[2] = {INT_MAX, 0};
int sum = 0, c = 0, cblock;

int main(void) {
    scanf("%d %d %d", &n, &m, &b);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
            sum += arr[i][j];
        }
    int height = (int) (sum / n / m);
    while (1) {
        if (height < 0 || height > 256) break;
        c = 0;
        cblock = b;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int count = arr[i][j] - height;
                if (count < 0)
                    c -= count;
                else c += count * 2;
                cblock += count;
            }
        if (cblock < 0) {
            height -= (int) (-cblock / (n * m)) + 1;
            continue;
        }
        if (result[0] > c) {
            result[0] = c;
            result[1] = height;
        } else if (result[0] == c && result[1] < height) result[1] = height;
        else {
            break;
        }
        height++;
    }
    printf("%d %d", result[0], result[1]);
}
