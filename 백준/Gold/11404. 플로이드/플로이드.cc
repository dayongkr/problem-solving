#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1e9

int dist[101][101];
int N, M, a, b, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    fill(&dist[0][0], &dist[100][101], INF);

    for (int i = 1; i <= N; i++)
        dist[i][i] = 0;

    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] == INF) cout << 0;
            else cout << dist[i][j];
            cout << " ";
        }
        cout << "\n";
    }


    return 0;
}
