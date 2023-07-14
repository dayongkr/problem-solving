#include <iostream>

using namespace std;

void rec(int s, int e, string result, int end_index) {
    if ((result.length() + 1) / 2 == end_index) {
        cout << result << '\n';
        return;
    }
    for (int i = s + 1; i <= e; i++) {
        string temp = result;
        temp.append(" ");
        temp.append(to_string(i));
        rec(i, e, temp, end_index);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        rec(i, N, to_string(i), M);
    }
    return 0;
}