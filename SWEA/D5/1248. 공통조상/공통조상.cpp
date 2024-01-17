#include <iostream>
#include <algorithm>

using namespace std;

int parent[10001], child[10001][2];

int getLevel(int node) {
    if (!parent[node]) return 1;
    return getLevel(parent[node]) + 1;
}

int getCommonAcestor(int a, int b) {
    int aLevel = getLevel(a), bLevel = getLevel(b), commonAcestor;

    if (aLevel - bLevel < 0) {
        for (int i = aLevel - bLevel; i < 0; ++i)
            b = parent[b];
    } else
        for (int i = aLevel - bLevel; i > 0; i--)
            a = parent[a];

    while (a != b) {
        a = parent[a];
        b = parent[b];
    }

    commonAcestor = a;
    return commonAcestor;
}

int getSize(int node) {
    if (node == 0) return 0;
    int left = getSize(child[node][0]), right = getSize(child[node][1]);
    return left + right + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T, V, E, X, Y;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> V >> E >> X >> Y;
        fill(parent, parent + 10001, 0);
        fill(&child[0][0], &child[10000][2], 0);

        for (int i = 0; i < E; i++) {
            int a, b;

            cin >> a >> b;
            parent[b] = a;
            if (child[a][0]) child[a][1] = b;
            else child[a][0] = b;
        }

        int commonAcestor = getCommonAcestor(X, Y), size = getSize(commonAcestor);
        cout << '#' << test_case << ' ' << commonAcestor << ' ' << size << '\n';
    }

    return 0;
}