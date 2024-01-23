#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<string> s1;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int result = 0, N, M;
        cin >> N >> M;
        s1.clear();
        for (int i = 0; i < N; i++) {
            string temp;
            cin >> temp;
            s1.emplace(temp);
        }

        for (int i = 0; i < M; i++) {
            string temp;
            cin >> temp;
            auto it = s1.find(temp);
            if (it != s1.end()) result += 1;
        }
        cout << '#' << test_case << ' ' << result << '\n';
    }
    return 0;
}