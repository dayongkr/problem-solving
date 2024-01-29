#include <bits/stdc++.h>

using namespace std;
#define MAX 200'000
int spaces[MAX], days[MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int N, P, temp, prev = 0, result = 0, total_space = 0;
        cin >> N >> P >> temp;
        days[0] = temp;
        spaces[0] = 0;
        prev = temp;
        for (int i = 1; i < N; i++) {
            cin >> temp;
            days[i] = temp;
            spaces[i] = total_space += temp - prev - 1;
            prev = temp;
        }
        for (int i = 0; i < N; i++) {
            int l = i, r = N - 1, temp = 0;
            while (l <= r) {
                int mid = l + (r - l) / 2, space = spaces[mid] - spaces[i];
                if (space <= P) {
                    temp = days[mid] - days[i] + P - space + 1;
                    l = mid + 1;
                } else r = mid - 1;
            }
            result = max(result, temp);
        }
        cout << '#' << test_case << ' ' << result << '\n';
    }
    return 0;
}