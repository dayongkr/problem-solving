#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> days, spaces;
int spaceCnt;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T, N, P;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        days.clear();
        spaces.clear();
        int temp, result = 0;
        spaceCnt = 0;
        cin >> N >> P;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            days.push_back(temp);
        }
        spaces.push_back(0);

        for (int i = 1; i < N; i++) {
            spaceCnt += days[i] - days[i - 1] - 1;
            spaces.push_back(spaceCnt);
        }
        for (int i = 0; i < N; i++) {
            int left = i, right = N - 1, mid = 0, cur;
            temp = 0;
            while (left <= right) {
                mid = left + (right - left) / 2;
                cur = spaces[mid] - spaces[i];
                if (cur <= P) {
                    temp = days[mid] - days[i] + 1 + P - cur;
                    left = mid + 1;
                } else right = mid - 1;
            }
            result = max(result, temp);
        }
        cout << '#' << test_case << ' ' << result << '\n';
    }
    return 0;
}