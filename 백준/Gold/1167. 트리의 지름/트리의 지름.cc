#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V, f, t, v, max_node, max_result = 0, value = 0;
vector<pair<int, int> > graph[100001];
int visited[100001] = {0};

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
    cin >> V;

    for (int i = 0; i < V; i++) {
        cin >> f;
        cin >> t;
        while(t != -1) {
            cin >> v;
            graph[f].emplace_back(t,v);
            graph[t].emplace_back(f,v);
            cin >> t;
        }
    }
    dfs(1);
    fill_n(visited, 100001, 0);
    dfs(max_node);
    cout << max_result;
    return 0;
}
