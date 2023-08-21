#include <iostream>
#include <queue>


using namespace std;

int V, E, visited[10001];
priority_queue<pair<int, pair<int, int>>> tree;

void input() {
    cin >> V >> E;
    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        tree.push({-c, {a, b}});
    }
}

int getParent(int n) {
    if (visited[n] == n) return n;
    return getParent(visited[n]);
}

void unionParent(int n1, int n2) {
    int p1 = getParent(n1), p2 = getParent(n2);
    if (p1 < p2)visited[p2] = p1;
    else visited[p1] = p2;
}

bool isCycle(int n1, int n2) {
    int p1 = getParent(n1), p2 = getParent(n2);
    return p1 == p2;
}

void solve() {
    int result = 0;
    for (int i = 1; i <= V; i++) visited[i] = i;
    while (!tree.empty()) {
        int cost = -tree.top().first;
        auto edge = tree.top().second;
        tree.pop();
        if (!isCycle(edge.first, edge.second)) {
            result += cost;
            unionParent(edge.first, edge.second);
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