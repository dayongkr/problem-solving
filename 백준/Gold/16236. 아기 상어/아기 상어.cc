#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define INF 1e9

int N, arr[20][20], shark_size = 2,
        dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1}, dist[20][20], t = 0, ate = 0;
pair<int, int> shark;

void input() {
    int temp;
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> temp;
            if (temp == 9) {
                shark = {i, j};
                temp = 0;
            }
            arr[i][j] = temp;
        }
}

void BFS() {
    queue<pair<int, int>> q;
    fill(&dist[0][0], &dist[19][20], INF);
    q.emplace(shark.first, shark.second);
    dist[shark.first][shark.second] = 0;
    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < N && dist[nr][nc] == INF && shark_size >= arr[nr][nc]) {
                q.emplace(nr, nc);
                dist[nr][nc] = dist[r][c] + 1;
            }
        }
    }
}


void solve() {
    while (true) {
        BFS();
        int min_dist = INF, r, c;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (dist[i][j] != INF && dist[i][j] < min_dist && arr[i][j] > 0 && arr[i][j] < shark_size) {
                    min_dist = dist[i][j];
                    r = i;
                    c = j;
                }
        if (min_dist == INF) break;
        shark = {r, c};
        arr[shark.first][shark.second] = 0;
        ate += 1;
        t += min_dist;
        if (shark_size <= ate) {
            shark_size++;
            ate = 0;
        }
    }
    cout << t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    return 0;
}