#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, f, t, v, max_node, max_result = 0, value = 0;
vector<pair<int, int> > graph[100001];
int visited[10001] = {0};

void dfs(int root) {
    visited[root] = 1;
    for (auto item: graph[root]) {
        if (!visited[item.first]) {
            value += item.second;
            if (max_result < value) {
                max_node = item.first;
                max_result = value;
            }
            dfs(item.first);
            value -= item.second;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        cin >> f >> t >> v;
        graph[f].emplace_back(t, v);
        graph[t].emplace_back(f, v);
    }
    dfs(1);
    fill_n(visited, 10001, 0);
    dfs(max_node);
    cout << max_result;
    return 0;
}
