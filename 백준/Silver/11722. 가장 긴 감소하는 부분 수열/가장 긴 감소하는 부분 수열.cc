#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, a[1000], dp[1000], result = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        int target = a[i];
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            if (target < a[j] && dp[i] < dp[j] + 1) dp[i] = dp[j] + 1;
        }
    }
    for (int i = 0; i < N; i++) if (dp[i] > result) result = dp[i];
    cout << result;
    return 0;
}