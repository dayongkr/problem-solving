#include <bits/stdc++.h>

using namespace std;

int x[1000], y[1000], visited[1000];
long long dist[1000];

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, temp;
        double E, ret = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            x[i] = temp;
        }
        for (int i = 0; i < N; i++) {
            cin >> temp;
            y[i] = temp;
        }
        cin >> E;
        // get MST
        memset(visited, 0, sizeof(visited));
        fill(dist, dist + 1000, INT64_MAX);
        int cur = 0;
        visited[0] = 1;
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < N; j++)
                if (!visited[j])
                    dist[j] = min(dist[j], 1LL * (x[cur] - x[j]) * (x[cur] - x[j]) +
                                           1LL * (y[cur] - y[j]) * (y[cur] - y[j]));
            cur = -1;
            for (int j = 0; j < N; j++) {
                if (visited[j])continue;
                if (cur == -1 || dist[cur] > dist[j]) cur = j;
            }
            visited[cur] = 1;
            ret += (double) dist[cur];
        }
        cout << fixed << setprecision(0) << '#' << t << ' ' << ret * E << '\n';
    }
    return 0;
}