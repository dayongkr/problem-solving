#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int bst[10001] = {0};

void rec(int s, int e) {
    if (s >= e) return;
    int root = bst[s];
    int i = s + 1;
    while ( i < e && bst[i] < root) i++;

    rec(s + 1, i);
    rec(i, e);
    cout << root << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int temp;
    int cnt = 0;
    while (cin >> temp) {
        bst[cnt++] = temp;
    }

    rec(0, cnt);
    return 0;
}