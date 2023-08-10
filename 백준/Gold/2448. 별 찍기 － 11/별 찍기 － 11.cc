#include <iostream>


using namespace std;

int N;
char arr[3072][6144];

void input() {
    cin >> N;
}

void rec(int n, int r, int c) {
    if (n == 3) {
        arr[r][c] = '*';
        arr[r + 1][c - 1] = '*';
        arr[r + 1][c + 1] = '*';
        for (int i = 0; i < 5; i++) {
            arr[r + 2][c - 2 + i] = '*';
        }
        return;
    }
    rec(n / 2, r, c);
    rec(n / 2, r + n / 2, c - n / 2);
    rec(n / 2, r + n / 2, c + n / 2);
}

void solve() {
    fill(&arr[0][0], &arr[3071][6144], ' ');
    rec(N, 0, N - 1);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++)
            cout << arr[i][j];
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    return 0;
}