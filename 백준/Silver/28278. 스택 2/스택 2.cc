#include <iostream>
#include <stack>

using namespace std;
stack<int> s;

int N;

void input() {
    cin >> N;
}

void solve() {
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp == 1) {
            cin >> temp;
            s.push(temp);
        } else if (temp == 2) {
            if (s.empty()) cout << -1;
            else {
                cout << s.top();
                s.pop();
            }
            cout << '\n';
        } else if (temp == 3) {
            cout << s.size();
            cout << '\n';
        } else if (temp == 4) {
            cout << (s.empty() ? 1 : 0);
            cout << '\n';
        } else {
            if (s.empty()) cout << -1;
            else cout << s.top();
            cout << '\n';
        }
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