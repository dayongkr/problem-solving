#include <iostream>
#include <unordered_map>

using namespace std;

int tree[1001];
unordered_map<int, pair<int, int>> childMap;

double inorder_traversal(int index, int size) {
    int cur = tree[index];
    if (cur >= 0) return cur;

    double leftSubset = inorder_traversal(childMap[index].first, size), rightSubset = inorder_traversal(
            childMap[index].second, size);

    if (cur + '0' == '+') return leftSubset + rightSubset;
    else if (cur + '0' == '-') return leftSubset - rightSubset;
    else if (cur + '0' == '*') return leftSubset * rightSubset;
    else if (cur + '0' == '/') return leftSubset / rightSubset;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T = 10, N, index, leftChildIndex, rightChildIndex;
    char value[11];
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> index >> value;
            if (value[0] < '0') {
                tree[index] = value[0] - '0';
                cin >> leftChildIndex >> rightChildIndex;
                childMap[index] = {leftChildIndex, rightChildIndex};
            } else
                tree[index] = (int) stoi(value);
        }
        cout << "#" << test_case << " " << (int) inorder_traversal(1, N) << '\n';
    }

    return 0;
}