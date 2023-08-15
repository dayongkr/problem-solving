#include <iostream>
#include <vector>

using namespace std;

int T;
vector<pair<int, int>> s;

void input() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        int x, y;
        cin >> x >> y;
        s.emplace_back(x, y);
    }
}

int gcd(int x, int y) {
    int n;
    while (y != 0) {
        n = x % y;
        x = y;
        y = n;
    }
    return x;
}

void solve() {
    for (auto item: s) {
        int g = gcd(max(item.first, item.second), min(item.first, item.second));
        cout << item.first * item.second / g << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    return 0;
}