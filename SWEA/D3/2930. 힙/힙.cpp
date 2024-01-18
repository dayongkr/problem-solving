#include <iostream>
#include <queue>

using namespace std;
priority_queue<int> pq = priority_queue<int>();

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T, N, type = 0, value;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        while (!pq.empty())
            pq.pop();
        cin >> N;
        cout << '#' << test_case;
        for (int i = 0; i < N; i++) {
            cin >> type;
            if (type == 1) {
                cin >> value;
                pq.push(value);
            } else {
                if (pq.empty())
                    cout << " -1";
                else {
                    cout << ' ' << pq.top();
                    pq.pop();
                }
            }
        }
        cout << '\n';
    }
    return 0;
}