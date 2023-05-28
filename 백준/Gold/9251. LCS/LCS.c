#include <stdio.h>
#include <string.h>

int main(void) {
    int dp[1001][1001], str1Size, str2Size;
    char str1[1001], str2[1001];
    scanf("%s", &str1);
    scanf("%s", &str2);
    str1Size = strlen(str1);
    str2Size = strlen(str2);

    // base case
    for (int i = 1; i <= str1Size; i++) {
        for (int j = 1; j <= str2Size; j++) {
            if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    printf("%d", dp[str1Size][str2Size]);
    return 0;
}