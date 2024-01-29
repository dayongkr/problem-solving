#include <bits/stdc++.h>

using namespace std;


int visited[1000], x[1000], y[1000];
long long dist[1000];

int main() {
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int N, X, Y;
        double E;
        long long result = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> X;
            x[i] = X;
        }
        for (int i = 0; i < N; i++) {
            cin >> Y;
            y[i] = Y;
        }
        cin >> E;
        memset(visited, 0, sizeof(visited));
        fill(dist, dist + 1000, LONG_LONG_MAX);
        int cur = 0;
        visited[0] = 1;
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N; j++) {
                dist[j] = min(dist[j],
                              1LL * (x[cur] - x[j]) * (x[cur] - x[j]) + 1LL * (y[cur] - y[j]) * (y[cur] - y[j]));
            }
            cur = -1;
            for (int j = 0; j < N; j++) {
                if (visited[j]) continue;
                if (cur == -1 || dist[j] < dist[cur]) cur = j;
            }
            visited[cur] = 1;
            result += dist[cur];
        }

        cout << fixed << setprecision(0) << '#' << test_case << ' ' << result * E << '\n';
    }
    return 0;
}