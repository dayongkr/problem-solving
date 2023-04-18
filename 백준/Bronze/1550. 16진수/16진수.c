#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    char str[7];
    int sum = 0;
    scanf("%s", str);
    int len = strlen(str), index = 0;
    for (int i = len - 1; i >= 0; i--) {
        sum += (str[i] >= 65 ? str[i] - 55 : str[i] - 48) * pow(16, index++);
    }
    printf("%d", sum);
    return 0;
}