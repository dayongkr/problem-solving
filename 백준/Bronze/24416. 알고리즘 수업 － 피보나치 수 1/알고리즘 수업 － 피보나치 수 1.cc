#include <iostream>
using namespace std;

int main() {
    int n, r2;
    cin >> n;
    r2 = n - 2;
    int dp[41] = {0,};
    dp[1] = dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n] << " " << r2;

    return 0;
}
