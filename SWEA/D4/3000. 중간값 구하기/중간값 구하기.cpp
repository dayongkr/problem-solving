#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T, N, result = 0, A, B;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        priority_queue<int> maxHeap;
        priority_queue<int, vector<int>, greater<>> minHeap;
        result = 0;
        cin >> N;
        cin >> A;
        maxHeap.push(A);
        for (int i = 0; i < N; ++i) {
            cin >> A >> B;
            if (A > maxHeap.top())
                minHeap.push(A);
            else
                maxHeap.push(A);
            if (B > maxHeap.top())
                minHeap.push(B);
            else
                maxHeap.push(B);

            if (maxHeap.size() > minHeap.size() + 1) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if (maxHeap.size() < minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }

            result = (result + maxHeap.top()) % 20171109;
        }
        cout << '#' << test_case << ' ' << result % 20171109 << '\n';
    }
    return 0;
}