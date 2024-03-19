#include <bits/stdc++.h>

using namespace std;

struct Trace {
    int row, col, hasSword, time;

    Trace(int row, int col, int hasSword, int time) : row(row), col(col), hasSword(hasSword), time(time) {}
};

int main() {
    int N, M, T, result, visited[100][100], visited2[100][100], graph[100][100],
            dx[4] = {1, 0, -1, 0},
            dy[4] = {0, 1, 0, -1};
    queue<Trace> q;

    cin >> N >> M >> T;
    result = T + 1;
    memset(visited, 0, sizeof(visited));
    memset(visited2, 0, sizeof(visited2));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    q.emplace(0, 0, 0, 0);
    visited[0][0] = 1;
    while (!q.empty()) {
        auto [row, col, hasSword, time] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = row + dy[i], nc = col + dx[i], ns = hasSword, nt = time + 1;
            if (nt > T) continue; // skip when over time
            if (nr == N - 1 && nc == M - 1) { // when meet princess
                result = min(result, nt);
                continue;
            }
            if (nr < 0 || nr >= N || nc < 0 || nc >= M || !hasSword && visited[nr][nc] ||
                hasSword && visited2[nr][nc])
                continue;
            int target = graph[nr][nc];
            if (target == 1 && !hasSword) continue;
            if (!ns)visited[nr][nc] = 1;
            else visited2[nr][nc] = 1;
            if (target == 2) ns = 1;
            q.emplace(nr, nc, ns, nt);
        }
    }
    if (result == T + 1) cout << "Fail";
    else cout << result;
}