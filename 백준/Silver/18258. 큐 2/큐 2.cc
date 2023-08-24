#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int> q;

void input() {
    cin >> N;
}

void solve() {
    string temp;
    int t;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp == "push") {
            cin >> t;
            q.push(t);
        } else if (temp == "front") {
            if (q.empty()) cout << -1;
            else cout << q.front();
            cout << '\n';
        } else if (temp == "back") {
            if (q.empty()) cout << -1;
            else cout << q.back();
            cout << '\n';
        } else if (temp == "empty") cout << (q.empty() ? 1 : 0) << '\n';
        else if (temp == "size") cout << q.size() << "\n";
        else {
            if (q.empty()) cout << -1;
            else {
                cout << q.front();
                q.pop();
            }
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