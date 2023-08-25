#include <iostream>
#include <deque>

using namespace std;

int N;
deque<int> q;

void input() {
    cin >> N;
}

void solve() {
    int temp;
    int t;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp == 1) {
            cin >> t;
            q.push_front(t);
        } else if (temp == 2) {
            cin >> t;
            q.push_back(t);
        } else if (temp == 3) {
            if (q.empty()) cout << -1;
            else {
                cout << q.front();
                q.pop_front();
            }
            cout << '\n';
        } else if (temp == 4) {
            if (q.empty()) cout << -1;
            else {
                cout << q.back();
                q.pop_back();
            }
            cout << '\n';
        } else if (temp == 6) cout << (q.empty() ? 1 : 0) << '\n';
        else if (temp == 5) cout << q.size() << "\n";
        else if (temp == 7) {
            if (q.empty()) cout << -1;
            else {
                cout << q.front();
            }
            cout << '\n';
        } else {
            if (q.empty()) cout << -1;
            else {
                cout << q.back();
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