#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<int> horse(500000), cow(500000);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T, N, M, C1, C2;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        int temp, MIN = INT_MAX, CNT = 1;
        horse.clear();
        cow.clear();
        cin >> N >> M >> C1 >> C2;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            cow.push_back(temp);
        }
        for (int i = 0; i < M; i++) {
            cin >> temp;
            horse.push_back(temp);
        }
        sort(cow.begin(), cow.end());

        for (int h: horse) {
            int left = 0, right = (int) cow.size() - 1, mid, dist, c;
            while (left <= right) {
                mid = left + (right - left) / 2;
                c = cow[mid];
                dist = abs(h - c);
                if (dist < MIN) {
                    MIN = dist;
                    CNT = 1;
                } else if (dist == MIN)
                    CNT++;
                if (h == c) break;
                else if (h > c) left = mid + 1;
                else right = mid - 1;
            }
        }

        cout << '#' << test_case << ' ' << MIN + abs(C1 - C2) << ' ' << CNT << '\n';
    }
    return 0;
}