#include <iostream>
#include <queue>
#include <vector>


using namespace std;

int N, M, arr[8][8], dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0}, cnt = 0, result = 0;
vector<pair<int, int>> virus;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) {
            int temp;
            cin >> temp;
            arr[i][j] = temp;
            if (temp == 2) virus.emplace_back(i, j);
            if (temp == 0) cnt++;
        }
}

void BFS() {
    int visited[8][8], copy_cnt = cnt;
    fill(&visited[0][0], &visited[7][8], 0);
    queue<pair<int, int>> q;
    for (auto item: virus) {
        q.emplace(item.first, item.second);
        visited[item.first][item.second] = 1;
    }
    while (!q.empty()) {
        int cr = q.front().first;
        int cc = q.front().second;
        q.pop();

        if (!arr[cr][cc])copy_cnt--;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i], nc = cc + dc[i];
            if (nr >= 0 && nr < N && nc < M && nc >= 0 && !visited[nr][nc] && arr[nr][nc] == 0) {
                visited[nr][nc] = 1;
                q.emplace(nr, nc);
            }
        }
    }
    result = max(result, copy_cnt);
}

void solve() {
    cnt -= 3;
    int nr[3], nc[3];
    for (int i = 0; i < N * M; i++) {
        nr[0] = i / M, nc[0] = i % M;
        if (!arr[nr[0]][nc[0]])
            for (int j = i; j < N * M; j++) {
                nr[1] = j / M, nc[1] = j % M;
                if (!arr[nr[1]][nc[1]])
                    for (int k = j; k < N * M; k++) {
                        nr[2] = k / M, nc[2] = k % M;
                        if (!arr[nr[2]][nc[2]]) {
                            arr[nr[0]][nc[0]] = 1;
                            arr[nr[1]][nc[1]] = 1;
                            arr[nr[2]][nc[2]] = 1;
                            BFS();
                            arr[nr[0]][nc[0]] = 0;
                            arr[nr[1]][nc[1]] = 0;
                            arr[nr[2]][nc[2]] = 0;
                        }
                    }
            }
    }
    cout << result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    return 0;
}