#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 2e9

int N, M, R, item[101], graph[101][101], dist[101];

void input() {
    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++)
        cin >> item[i];
    fill(&graph[0][0], &graph[100][101], INF);
    for (int i = 0; i < R; i++) {
        int f, t, v;
        cin >> f >> t >> v;
        graph[f][t] = v;
        graph[t][f] = v;
    }
}

void dijkstra(int s) {
    priority_queue<pair<int, int>> pq;
    fill_n(dist, 101, INF);
    dist[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty()) {
        int cur = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        if (dist[cur] < cur_dist) continue;

        for (int i = 1; i <= N; i++) {
            int next_distance = cur_dist + graph[cur][i];
            if (next_distance < dist[i]) {
                dist[i] = next_distance;
                pq.emplace(-next_distance, i);
            }
        }
    }
}

void solve() {
    int result = 0;
    for (int i = 1; i <= N; i++) {
        int cur = 0;
        dijkstra(i);
        for (int j = 1; j <= N; j++) {
            if (dist[j] <= M) cur += item[j];
        }
        result = max(cur, result);
    }
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    return 0;
}