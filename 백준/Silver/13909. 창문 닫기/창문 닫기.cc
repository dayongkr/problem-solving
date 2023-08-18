#include <iostream>
#include <cmath>

using namespace std;

int N;

void input() {
    cin >> N;
}


void solve() {
    if (N == 1) cout << 1;
    else cout << (int) pow(N, 0.5);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    return 0;
}