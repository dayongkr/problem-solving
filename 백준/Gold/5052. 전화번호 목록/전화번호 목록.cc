#include <bits/stdc++.h>

using namespace std;
static constexpr char OFFSET = '0';

string s;

struct node {
    int child[10];
    bool is_terminal;

    node() {
        memset(child, -1, sizeof(child));
        is_terminal = false;
    }
};

vector<node> nodes;

bool insert() {
    int cur = 0, cont = 1;
    for (char c: s) {
        if (nodes[cur].child[c - OFFSET] == -1) {
            nodes[cur].child[c - OFFSET] = nodes.size();
            nodes.emplace_back();
            cont = 0;
        }
        cur = nodes[cur].child[c - OFFSET];
        if (cont && nodes[cur].is_terminal) return true;
    }
    nodes[cur].is_terminal = true;
    if (cont && nodes[cur].is_terminal) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T, N;
    cin >> T;
    for (int i = 0; i < T; i++) {
        bool can = true;
        nodes.clear();
        nodes.emplace_back();
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> s;
            if (insert()) {
                can = false;
            }
        }
        if (can) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}