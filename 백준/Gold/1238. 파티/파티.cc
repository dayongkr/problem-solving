#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define INF 1e9

int N, M, X, A, B, T, dist[1001], dist2[1001], result = 0;
vector<pair<int, int> > graph[1001];

void dijkstra(int s) {
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, s);
    fill_n(dist, 1001, INF);
    dist[s] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cur_dist = -pq.top().first;
        pq.pop();

        if (dist[cur] < cur_dist) continue;

        for (auto item: graph[cur]) {
            int next_dist = cur_dist + item.second;
            if (next_dist < dist[item.first]) {
                dist[item.first] = next_dist;
                pq.emplace(-next_dist, item.first);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        cin >> A >> B >> T;
        graph[A].emplace_back(B, T);
    }
    dijkstra(X);
    for (int i = 1; i <= N; i++)
        dist2[i] = dist[i];

    for (int i = 1; i <= N; i++) {
        if (i == X) continue;
        dijkstra(i);
        result = max(result, dist2[i] + dist[X]);
    }
    cout << result;

    return 0;
}