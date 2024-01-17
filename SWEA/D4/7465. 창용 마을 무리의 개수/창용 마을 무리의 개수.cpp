#include <iostream>
#include <algorithm>

using namespace std;

int set[101], parent[101], Rank[101];

int find(int x) {
    if (x == set[x]) return x;
    else return set[x] = find(set[x]);
}

void setUnion(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (Rank[x] < Rank[y]) set[x] = y;
    else {
        set[y] = x;
        if (Rank[x] == Rank[y]) Rank[x]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T, N, M, A, B;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N >> M;
        int count = 0;
        fill(parent, parent + 101, 0);

        for (int i = 1; i <= N; i++)
            set[i] = i;
        for (int i = 0; i < M; i++) {
            cin >> A >> B;
            setUnion(A, B);
        }
        for (int i = 1; i <= N; i++) {
            int acestor = find(set[i]);
            if (!parent[acestor]) {
                count++;
                parent[acestor] = 1;
            }
        }
        cout << '#' << test_case << ' ' << count << '\n';
    }

    return 0;
}