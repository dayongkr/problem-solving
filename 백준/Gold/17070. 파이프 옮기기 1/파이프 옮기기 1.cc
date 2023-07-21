#include <iostream>
#include <queue>

using namespace std;

int N;
int graph[17][17];

struct dir {
    int r, c, type;
};

queue<dir> q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> graph[i][j];
        }
    }
    q.push({1, 2, 0});
    if (!graph[N][N])
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();

            int r = cur.r;
            int c = cur.c;
            int type = cur.type;
            vector<dir> nd;

            if (r == N && c == N) {
                cnt++;
            }

            if (type == 0) { // 현재 가로
                nd.push_back({r, c + 1, 0});
            } else if (type == 1) { // 세로
                nd.push_back({r + 1, c, 1});
            } else { // 대각선
                nd.push_back({r, c + 1, 0});
                nd.push_back({r + 1, c, 1});
            }
            nd.push_back({r + 1, c + 1, 2});

            for (auto item: nd) {
                int nr = item.r;
                int nc = item.c;
                if (nc > N || nr > N || graph[nr][nc] ||
                    (item.type == 2 &&
                     (graph[nr - 1][nc] || graph[nr][nc - 1]))) // 밖으로 넘어가거나 갈 곳이 빈칸이 아니면 넘어가기 + 대각선이면 추가로 벽 확인
                    continue;
                q.push({nr, nc, item.type});
            }
        }
    cout << cnt;
    return 0;
}

