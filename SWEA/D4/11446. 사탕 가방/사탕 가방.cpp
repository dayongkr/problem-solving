#include <iostream>
#include <climits>

using namespace std;
typedef long long ll;
ll nums[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T, N;
    ll M;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        ll temp;
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            nums[i] = temp;
        }
        ll left = 1, right = LONG_LONG_MAX, mid, result = 0;

        while (left <= right) {
            mid = left + ((right - left) / 2);
            ll sum = 0;
            for (int i = 0; i < N; i++)
                sum += nums[i] / mid;

            if (sum >= M) {
                result = mid;
                left = mid + 1;
            }
            else right = mid - 1;
        }

        cout << '#' << test_case << ' ' << result << '\n';
    }
    return 0;
}