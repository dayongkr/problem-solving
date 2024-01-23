#include <iostream>
#include <queue>
#include <climits>

#define INF INT_MAX

using namespace std;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
int graph[100][100], dist[100][100], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T, N;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        pq = priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>>();
        cin >> N;
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < N; j++) {
                graph[i][j] = s[j] - '0';
            }
        }
        fill(&dist[0][0], &dist[N - 1][N], INF);
        dist[0][0] = 0;
        pq.emplace(0, make_pair(0, 0));
        while (!pq.empty()) {
            pair<int, int> cur_node = pq.top().second;
            int cur_dist = pq.top().first;
            pq.pop();
            if (cur_dist < dist[cur_node.second][cur_node.first]) continue;
            for (int i = 0; i < 4; i++) {
                pair<int, int> next_node = {cur_node.first + dx[i], cur_node.second + dy[i]};
                if (next_node.first < N && next_node.first >= 0 && next_node.second < N && next_node.second >= 0) {
                    int next_dist = cur_dist + graph[next_node.second][next_node.first];
                    if (next_dist < dist[next_node.second][next_node.first]) {
                        dist[next_node.second][next_node.first] = next_dist;
                        pq.emplace(next_dist, next_node);
                    }
                }
            }
        }
        cout << '#' << test_case << ' ' << dist[N - 1][N - 1] << '\n';
    }
    return 0;
}