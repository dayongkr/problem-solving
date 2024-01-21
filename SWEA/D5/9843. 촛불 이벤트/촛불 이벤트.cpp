#include <iostream>
#include <climits>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T;
    ll N;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N;
        ll left = 1, right = INT_MAX, mid, require, result = -1;

        while (left <= right) {
            mid = left + ((right - left) / 2);
            require = mid * (mid + 1) / 2;
            if (require == N) {
                result = mid;
                break;
            } else if (require < N)
                left = mid + 1;
            else right = mid - 1;
        }

        cout << '#' << test_case << ' ' << result << '\n';
    }
    return 0;
}