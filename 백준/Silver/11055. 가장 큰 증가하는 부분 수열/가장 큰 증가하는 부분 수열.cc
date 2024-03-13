#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, a[1000], dp[1001], ret = 0;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> a[i];
    for (int i = 0; i < N; i++) {
        dp[i] = a[i];
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + a[i]);
        }
        ret = max(dp[i], ret);
    }
    cout << ret;
}