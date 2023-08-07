#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

int N, M, T, temp;

set<int> known;
vector<int> party[50];
set<int> graph[51];

void input() {
    cin >> N >> M >> T;

    for (int i = 0; i < T; i++) {
        cin >> temp;
        known.insert(temp);
    }

    for (int i = 0; i < M; i++) {
        cin >> T;
        for (int j = 0; j < T; j++) {
            cin >> temp;
            party[i].push_back(temp);
        }
    }

}

void BFS() {
    queue<int> q;
    int visited[51] = {0};
    for (auto item: known) {
        q.push(item);
        visited[item] = 1;
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto item: graph[cur]) {
            if (!visited[item]) {
                known.insert(item);
                visited[item] = 1;
                q.push(item);
            }
        }
    }
}

int solve() {
    int cnt = 0, found;
    for (int i = 0; i < M; i++)
        for (auto item: party[i])
            for (auto other: party[i]) {
                if (item == other) continue;
                graph[item].insert(other);
                graph[other].insert(item);
            }


    BFS();

    for (int i = 0; i < M; i++) {
        found = 0;
        for (auto item: party[i])
            if (known.find(item) != known.end())
                found = 1;
        if (!found) cnt++;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    cout << solve();

    return 0;
}