#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define INF 1e9

int N, E, V1, V2, graph[801][801], dist[801];


void input() {
    int a, b, c;
    cin >> N >> E;
    fill(&graph[0][0], &graph[800][801], INF);
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
        graph[b][a] = min(graph[b][a], c);
    }
    cin >> V1 >> V2;
}

void dijkstra(int s) {
    priority_queue<pair<int, int>> q;

    fill(dist, dist + N + 1, INF);
    q.emplace(0, s);
    dist[s] = 0;

    while (!q.empty()) {
        int cost = -q.top().first;
        int cur = q.top().second;
        q.pop();

        if (dist[cur] < cost) continue;

        for (int i = 1; i <= N; i++) {
            int n_cost = cost + graph[cur][i];
            if (dist[i] > n_cost) {
                dist[i] = n_cost;
                q.emplace(-n_cost, i);
            }
        }
    }
}

void solve() {
    int toV1, toV2, V1toV2, V1toN, V2toN, dist1, dist2;
    dijkstra(V1);
    toV1 = dist[1];
    V1toV2 = dist[V2];
    V1toN = dist[N];
    dijkstra(V2);
    toV2 = dist[1];
    V2toN = dist[N];

    dist1 = toV1 + V1toV2 + V2toN;
    dist2 = toV2 + V1toV2 + V1toN;

    if ((dist1 < 3 ||dist1 >= INF) and (dist2 < 3 || dist2 >= INF))
        cout << -1;
    else
        cout << min(dist1, dist2);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();

    return 0;
}