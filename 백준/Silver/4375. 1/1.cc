#include <iostream>
#include <vector>

using namespace std;

vector<int> nums;

void input() {
    int temp;
    while (1) {
        cin >> temp;
        if (cin.eof()) break;
        nums.push_back(temp);
    }
}

void solve() {
    for (int item: nums) {
        int result = 1, cnt = 1;
        while (result % item != 0) {
            result *= 10;
            result += 1;
            result %= item;
            cnt++;
        }
        cout << cnt << '\n';
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