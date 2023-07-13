#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    int dp[1025][1025];

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }
            cin >> dp[i][j];
            dp[i][j] += dp[i - 1][j];
            if (j != 1)
                dp[i][j] += dp[i][j - 1] - dp[i - 1][j - 1];

        }

    for (int i = 0; i < M; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << "\n";
    }
    return 0;
}