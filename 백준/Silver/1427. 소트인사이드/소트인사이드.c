#include <stdio.h>
#include <string.h>

int main(void) {
    char c[11];
    scanf("%s", c);
    int size = strlen(c);

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (c[j] < c[j + 1]) {
                char temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
    printf("%s\n", c);
}
