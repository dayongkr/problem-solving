#include <iostream>
#include <map>

using namespace std;

int R, C, visited[20][20] = {0}, dr[4] = {0, 0, 1, -1}, dc[4] = {1, -1, 0, 0}, result = 0;
string graph[20];
map<char, bool> visitedChar;


void input() {
    cin >> R >> C;
    for (int i = 0; i < R; i++)
        cin >> graph[i];
}

void DFS(int r, int c, int cnt) {
    result = max(result, cnt);
    visitedChar[graph[r][c]] = true;
    visited[r][c] = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (nr >= 0 && nr < R && nc >= 0 && nc < C && !visited[nr][nc] &&
            !visitedChar[graph[nr][nc]]) {
            visited[nr][nc] = 1;
            visitedChar[graph[nr][nc]] = true;
            DFS(nr, nc, cnt + 1);
            visited[nr][nc] = 0;
            visitedChar[graph[nr][nc]] = false;
        }
    }
}

void solve() {
    for (char i = 'A'; i <= 'Z'; i++)
        visitedChar.emplace(i, false);
    DFS(0, 0, 1);
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