#include <iostream>
#include <algorithm>

using namespace std;

char tree[101];

void inorder_traversal(int index, int size) {
    if (index > size)
        return;
    inorder_traversal(index * 2, size);
    cout << tree[index];
    inorder_traversal(index * 2 + 1, size);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case, T = 10, N, index, child;
    char temp;
    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N;
        fill(tree, tree + 101, 0);
        for (int i = 0; i < N; ++i) {
            cin >> index >> temp;
            tree[index] = temp;
            if (child != N) {
                cin >> child;
                if (child < N) {
                    cin >> child;
                }
            }
        }
        cout << "#" << test_case << " ";
        inorder_traversal(1, N);
        cout << '\n';
    }

    return 0;
}