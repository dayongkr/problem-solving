#include <iostream>
#include <queue>


using namespace std;

int N, K, min_t = 100001, ways = 0, visited[100001];

void input() {
    cin >> N >> K;
    fill_n(visited, 100001, 100001);
}

void BFS() {
    queue<pair<int, int>> q;
    q.emplace(N, 0);

    visited[N] = 0;

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        int n_cnt = cnt + 1;
        if (cur == K) {
            ways++;
            if (cnt < min_t)
                min_t = cnt;
        }
        q.pop();

        if (min_t >= n_cnt) {
            if (cur * 2 < 100001 && visited[cur * 2] >= n_cnt) {
                q.emplace(cur * 2, n_cnt);
                visited[cur * 2] = n_cnt;
            }
            if (cur + 1 < 100001 && visited[cur + 1] >= n_cnt) {
                q.emplace(cur + 1, n_cnt);
                visited[cur + 1] = n_cnt;
            }
            if (cur - 1 >= 0 && visited[cur - 1] >= n_cnt) {
                q.emplace(cur - 1, n_cnt);
                visited[cur - 1] = n_cnt;
            }
        }

    }

}

void solve() {
    BFS();
    cout << min_t << '\n' << ways;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    return 0;
}