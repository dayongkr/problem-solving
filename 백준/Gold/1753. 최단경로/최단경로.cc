#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 1e9

int dist[20001];
vector<pair<int, int>> graph[20001];
priority_queue<pair<int, int>> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int V, E, K, u, v, w;
    cin >> V >> E >> K;

    fill(dist, dist + 20001, INF);

    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    dist[K] = 0;
    q.emplace(0, K);

    while (!q.empty()) {
        auto cur = q.top();
        int cur_dist = -cur.first;
        int cur_from = cur.second;
        q.pop();
        if (dist[cur_from] < cur_dist) continue;
        for (auto item: graph[cur_from]) {
            int next_distance = cur_dist + item.second;
            if (dist[item.first] > next_distance) {
                dist[item.first] = next_distance;
                q.emplace(-next_distance, item.first);
            }
        }
    }
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << '\n';
    }
    return 0;
}

