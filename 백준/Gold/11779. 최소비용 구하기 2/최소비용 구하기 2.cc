#include <iostream>
#include <queue>
#include <vector>


using namespace std;

#define INF 1e9

int N, M, S, D, graph[1001][1001], dist[1001];
vector<int> visited_city[1001];

void input() {
    cin >> N >> M;
    fill(&graph[0][0], &graph[1000][1001], INF);
    for (int i = 0; i < M; i++) {
        int a, b, cost;
        cin >> a >> b >> cost;
        if (graph[a][b] > cost)
            graph[a][b] = cost;
    }
    cin >> S >> D;
}

void dijkstra(int s) {
    priority_queue<pair<int, int>> pq;
    fill_n(dist, 1001, INF);
    pq.emplace(0, s);
    dist[s] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second;
        int cur_dist = -pq.top().first;
        if (visited_city[cur].empty()) visited_city[cur].push_back(cur);
        pq.pop();

        if (dist[cur] < cur_dist) continue;

        for (int i = 1; i <= N; i++) {
            int next_dist = cur_dist + graph[cur][i];
            if (next_dist < dist[i]) {
                dist[i] = next_dist;
                visited_city[i].clear();
                for (auto item: visited_city[cur])
                    visited_city[i].push_back(item);
                visited_city[i].push_back(i);
                pq.emplace(-next_dist, i);
            }
        }
    }
}

void solve() {
    dijkstra(S);
    cout << dist[D] << '\n';
    cout << visited_city[D].size() << '\n';
    for (auto item: visited_city[D]) cout << item << ' ';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    return 0;
}