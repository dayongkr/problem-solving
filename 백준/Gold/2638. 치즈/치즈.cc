#include <iostream>
#include <queue>


using namespace std;

int N, M, arr[101][101], visited[101][101] = {0},
        cnt = 0, dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1}, t = 0;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            int temp;
            cin >> temp;
            if (temp) cnt++;
            arr[i][j] = temp;
        }
}

void BFS() {
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    fill(&visited[0][0], &visited[100][101], 0);
    visited[0][0] = 1;
    while (!q.empty()) {
        int r = q.front().first, c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr >= 0 && nr < N && nc >= 0 && nc < M) {
                if (arr[nr][nc]) {
                    visited[nr][nc]++;
                    if (visited[nr][nc] >= 2) {
                        arr[nr][nc] = 0;
                        cnt--;
                    }
                } else if (!visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    q.emplace(nr, nc);
                }
            }
        }
    }
}

void solve() {
    while (cnt) {
        t++;
        BFS();
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