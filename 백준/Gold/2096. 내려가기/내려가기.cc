#include <iostream>

using namespace std;

int N, input[3], maxDp[3] = {0}, minDp[3], temp[2];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;
    for (int i = 0; i < 3; i++) {
        cin >> maxDp[i];
        minDp[i] = maxDp[i];
    }

    for (int i = 1; i < N; i++) {
        for (int & j : input)
            cin >> j;
        temp[0] = maxDp[0];
        temp[1] = maxDp[2];
        maxDp[0] = max(maxDp[0], maxDp[1]) + input[0];
        maxDp[2] = max(maxDp[1], maxDp[2]) + input[2];
        maxDp[1] = max(max(temp[0], maxDp[1]), temp[1]) + input[1];
        temp[0] = minDp[0];
        temp[1] = minDp[2];
        minDp[0] = min(minDp[0], minDp[1]) + input[0];
        minDp[2] = min(minDp[1], minDp[2]) + input[2];
        minDp[1] = min(min(temp[0], minDp[1]), temp[1]) + input[1];
    }
    cout << max(max(maxDp[0], maxDp[1]), maxDp[2]) << ' ' << min(min(minDp[0], minDp[1]), minDp[2]);
    return 0;
}