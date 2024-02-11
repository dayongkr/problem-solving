#include <bits/stdc++.h>

using namespace std;
#define BASE 123
const long long MOD = 1e5 + 3;

long long mod(long long a) {
    if (a >= 0) return a % MOD;
    else return ((-a / MOD + 1) * MOD + a) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int L;
    string s;
    cin >> L >> s;
    int ret = 0, l = 0, r = L;
    while (l <= r) {
        int mid = (l + r) / 2, hashing = 0, found = 0;
        long long power = 1;

        vector<int> hashed[MOD + 1];
        for (int i = 0; i + mid <= L; i++) {
            if (i == 0) {
                for (int j = 0; j < mid; j++) {
                    hashing = mod(mod(hashing * BASE) + s[j] - 'a' + 1);
                    if (j != mid - 1) power = mod(power * BASE);
                }
            } else {
                hashing = mod(mod(BASE * (hashing - mod(power * (s[i - 1] - 'a' + 1)))) + s[i + mid - 1] - 'a' + 1);
            }
            if (!hashed[hashing].empty()) {
                for (auto j: hashed[hashing]) {
                    int can = 1;
                    for (int k = 0; k < mid; k++) {
                        if (s[i + k] != s[j + k]) {
                            can = 0;
                            break;
                        }
                    }
                    if (can) {
                        found = 1;
                        break;
                    }
                }
            }

            if (found) {
                ret = mid;
                break;
            } else hashed[hashing].push_back(i);
        }
        if (found) l = mid + 1;
        else r = mid - 1;
    }
    cout << ret;
}