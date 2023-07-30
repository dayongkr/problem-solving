#include <iostream>
#include <queue>
#include <tuple>
#include <string>

using namespace std;

int N, M, graph[1001][1001], visited[2][1001][1001], result = -1;
pair<int, int> d[4] = {{1,  0},
                       {0,  1},
                       {-1, 0},
                       {0,  -1}};

void bfs(int r, int c) {
    queue<tuple<int, int, int, int>> q;
    q.emplace(r, c, 0, 1);
    visited[0][r][c] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        int row = get<0>(cur), col = get<1>(cur), broken = get<2>(cur), count = get<3>(cur);
        if (row == N && col == M) {
            result = count;
            break;
        }
        q.pop();
        for (auto item: d) {
            int nr = row + item.first, nc = col + item.second;
            if (nr >= 1 && nr <= N && nc >= 1 && nc <= M && !visited[broken][nr][nc]) {
                if (broken && !graph[nr][nc]) {
                    q.emplace(nr, nc, broken, count + 1);
                    visited[1][nr][nc] = 1;
                } else if (!broken && graph[nr][nc]) {
                    q.emplace(nr, nc, 1, count + 1);
                    visited[1][nr][nc] = 1;
                } else if (!broken && !graph[nr][nc]) {
                    q.emplace(nr, nc, broken, count + 1);
                    visited[0][nr][nc] = visited[1][nr][nc] = 1;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        string temp;
        cin >> temp;
        for (int j = 1; j <= M; j++)
            graph[i][j] = (int) temp[j - 1] - 48;
    }


    bfs(1, 1);
    cout << result;
    return 0;
}