#include <bits/stdc++.h>

using namespace std;

int H, W, N, arr[100][2], result = 0;

void check(int cr, int cc, int i) {
    int tr = W - cr, tc = H - cc;
    if (tr < 0 || tc < 0) return;
    for (int j = i + 1; j < N; j++) {
        int nr = arr[j][0], nc = arr[j][1];
        if (tr >= nr && H >= nc || tr >= nc && H >= nr || tc >= nr && W >= nc || tc >= nc && W >= nr) {
            result = max(result, cr * cc + nr * nc);
        }
    }
}

int main() {
    cin >> H >> W >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    for (int i = 0; i < N; i++) {
        int cr = arr[i][0], cc = arr[i][1];
        check(cr, cc, i);
        check(cc, cr, i);
    }
    cout << result;
    return 0;
}