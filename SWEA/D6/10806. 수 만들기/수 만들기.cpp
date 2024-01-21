#include <iostream>
#include <queue>

using namespace std;

int nums[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T, N;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap;
        int A, K;
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> A;
            nums[i] = A;
        }
        cin >> K;
        heap.emplace(0, K);
        while (heap.top().second) {
            auto cur = heap.top();
            heap.pop();
            heap.emplace(cur.first + cur.second, 0);
            for (int i = 0; i < N; i++)
                heap.emplace(cur.first + cur.second % nums[i], cur.second / nums[i]);
        }
        cout << '#' << test_case << ' ' << heap.top().first << '\n';
    }
    return 0;
}