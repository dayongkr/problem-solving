#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, f, t, v, max_node, max_result = 0, value = 0;
vector<pair<int, int> > graph[100001];
int visited[100001] = {0};

void reset() {
    max_result=0;
    value=0;
    fill_n(visited, 100001, 0);
}

pair<int, int> dfs(int root, int except = 0) {
    visited[root] = 1;
    visited[except] = 1;
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
    return {max_node, max_result};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;

    for (int i = 1; i < N; i++) {
        cin >> f >> t >> v;
        graph[f].emplace_back(t, v);
        graph[t].emplace_back(f, v);
    }
    int a = dfs(1).first;
    reset();
    int b = dfs(a).first;
    reset();
    int A = dfs(a, b).second;
    reset();
    int B = dfs(b, a).second;

    cout << max(A, B);
    return 0;
}