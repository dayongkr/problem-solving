#include <iostream>
#include <algorithm>

using namespace std;

int N;
int board[15];
int cnt = 0;

bool check(int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i] == col || row - i == abs(col - board[i]))
            return false;
    return true;
}

void rec(int row) {
    if (row == N) {
        cnt++;
        return;
    }
    for (int i = 0; i < N; i++) {
        if (check(row, i)) {
            board[row] = i;
            rec(row + 1);
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    rec(0);
    cout << cnt;
    return 0;
}
