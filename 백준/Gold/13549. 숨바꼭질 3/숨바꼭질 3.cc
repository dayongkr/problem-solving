#include <iostream>
#include <queue>

using namespace std;

int out[100001] = {0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    queue<pair<int, int>> q;

    int N, K;
    cin >> N >> K;

    q.push({N, 0});
    while (!q.empty()) {
        int to = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (to == K) {
            cout << cnt;
            break;
        }
        if (to * 2 <= 100000 && !out[to * 2]) {
            q.push({to * 2, cnt});
            out[to * 2] = 1;
        }
        if (to - 1 >= 0 && !out[to - 1]) {
            q.push({to - 1, cnt + 1});
            out[to - 1] = 1;
        }
        if (to + 1 <= 100000 && !out[to + 1]) {
            q.push({to + 1, cnt + 1});
            out[to + 1] = 1;
        }
    }
    return 0;
}

