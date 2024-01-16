#include <iostream>
#include <algorithm>

using namespace std;

char tree[201], prevNode = 0;
int possible;

void inorder_traversal(int index, int size) {
    if (index > size || !possible)
        return;

    inorder_traversal(index << 1, size);
    char curNode = tree[index];
    if (prevNode && ((prevNode >= '0' && curNode >= '0') || (prevNode < '0' && curNode < '0'))) {
        possible = 0;
        return;
    }
    prevNode = curNode;
    inorder_traversal((index << 1) + 1, size);
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
        prevNode = 0;
        possible = 1;
        inorder_traversal(1, N);
        cout << "#" << test_case << " " << possible << '\n';
    }

    return 0;
}