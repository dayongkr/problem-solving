#include <bits/stdc++.h>

using namespace std;

int g[50][50], visited[50][50], sum = 0, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, N, L, R;
vector<pair<int, int>> track;

void dfs(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = dy[i] + r, nc = dx[i] + c, diff = abs(g[r][c] - g[nr][nc]);
        if (nr < N && nr >= 0 && nc < N && nc >= 0 && !visited[nr][nc] && diff >= L && diff <= R) {
            visited[nr][nc] = 1;
            track.emplace_back(nr, nc);
            sum += g[nr][nc];
            dfs(nr, nc);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int day = 0;
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> g[i][j];
        }
    }
    while (1) {
        int changed = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (visited[i][j]) continue;
                dfs(i, j);
                int len = (int) track.size();
                if (len <= 1) continue;
                changed = sum / len;
                for (auto [tr, tc]: track) {
                    g[tr][tc] = changed;
                }
                sum = 0;
                track.clear();
            }
        }
        if (!changed) break;
        day++;
    }
    cout << day;
}