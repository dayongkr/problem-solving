#include <iostream>
#include <algorithm>

using namespace std;

int N, K, dp[101][100001];
pair<int, int> items[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        int W, V;
        cin >> W >> V;
        items[i] = make_pair(W, V);
    }

    fill_n(&dp[0][0], 101 * 100001, 0);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= K; j++) {
            int w = items[i].first, v = items[i].second;
            if (w <= j)
                dp[i][j] = max(v + dp[i - 1][j - w], dp[i - 1][j]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    cout << dp[N][K];
    return 0;
}