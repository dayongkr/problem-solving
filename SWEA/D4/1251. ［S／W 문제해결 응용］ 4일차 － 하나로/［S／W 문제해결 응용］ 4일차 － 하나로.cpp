#include <bits/stdc++.h>

using namespace std;

int x[1000], y[1000], visited[1000];
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N, temp, visit_cnt = 0;
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
        pq = {};
        memset(visited, 0, sizeof(visited));
        pq.emplace(0, 0);
        while (!pq.empty()) {
            if (visit_cnt == N) break;
            auto [cur_dist, cur] = pq.top();
            pq.pop();
            if (visited[cur]) continue;
            visited[cur] = 1;
            visit_cnt++;
            ret += (double) cur_dist;
            for (int i = 0; i < N; i++) {
                if (visited[i]) continue;
                int x1 = x[cur], y1 = y[cur], x2 = x[i], y2 = y[i];
                pq.emplace(1LL * (x1 - x2) * (x1 - x2) + 1LL * (y1 - y2) * (y1 - y2), i);
            }
        }
        cout << fixed << setprecision(0) << '#' << t << ' ' << ret * E << '\n';
    }
    return 0;
}