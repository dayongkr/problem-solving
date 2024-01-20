#include <iostream>
#include <queue>

using namespace std;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<>> minHeap;

void init() {
    maxHeap = priority_queue<int>();
    minHeap = priority_queue<int, vector<int>, greater<>>();
}

void push() {
    int num;
    cin >> num;
    if (maxHeap.size() == minHeap.size()) {
        maxHeap.push(num);
    } else {
        minHeap.push(num);
    }
    if (!maxHeap.empty() && !minHeap.empty() && maxHeap.top() > minHeap.top()) {
        int maxTop = maxHeap.top();
        int minTop = minHeap.top();
        maxHeap.pop();
        minHeap.pop();
        maxHeap.push(minTop);
        minHeap.push(maxTop);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T, N, result = 0;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        //clear
        init();
        result = 0;
        cin >> N;
        push();
        for (int i = 0; i < N; ++i) {
            push();
            push();
            result = (result + maxHeap.top()) % 20171109;
        }
        cout << '#' << test_case << ' ' << result % 20171109 << '\n';
    }
    return 0;
}