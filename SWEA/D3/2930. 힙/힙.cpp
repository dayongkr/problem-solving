#include <iostream>

using namespace std;

int queue[100001], queue_size = 0;

void init() {
    for (int & i : queue)
        i = 0;
    queue_size = 0;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void push(int value) {
    queue[++queue_size] = value;
    int index = queue_size, parent = index / 2;
    while (parent != 0 && queue[index] > queue[parent]) {
        swap(queue[index], queue[parent]);
        index = index / 2;
        parent = index / 2;
    }
}

int pop() {
    if (queue_size == 0) return -1;
    int result = queue[1], parent = 1, large = 1, left = 2, right = 3;
    swap(queue[1], queue[queue_size--]);
    while (true) {
        if (left <= queue_size && queue[left] > queue[large]) large = left;
        if (right <= queue_size && queue[right] > queue[large]) large = right;
        if (large == parent) break;
        swap(queue[parent], queue[large]);
        parent = large;
        left = parent * 2;
        right = left + 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T, N, type = 0, value;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        init();
        cin >> N;
        cout << '#' << test_case;
        for (int i = 0; i < N; i++) {
            cin >> type;
            if (type == 1) {
                cin >> value;
                push(value);
            } else {
                cout << ' ' << pop();
            }
        }
        cout << '\n';
    }

    return 0;
}