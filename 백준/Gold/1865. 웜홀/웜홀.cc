#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define INF 1e9
int F, N, M, W, S, E, T, dist[501];
vector<tuple<int, int, int>> vertex;

bool bellman(int s) {
    fill_n(dist, 501, INF);
    dist[s] = 0;
    for (int i = 1; i <= N; i++)
        for (auto item: vertex) {
            int from = get<0>(item);
            int to = get<1>(item);
            int value = get<2>(item);
            if (dist[to] > dist[from] + value) {
                dist[to] = dist[from] + value;
                if (i == N) return true;
            }
        }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> F;
    for (int i = 0; i < F; i++) {
        cin >> N >> M >> W;
        vertex.clear();
        for (int j = 0; j < M; j++) {
            cin >> S >> E >> T;
            vertex.emplace_back(S, E, T);
            vertex.emplace_back(E, S, T);
        }
        for (int j = 0; j < W; j++) {
            cin >> S >> E >> T;
            vertex.emplace_back(S, E, -T);
        }
        if (bellman(1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}