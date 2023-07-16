#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<int> answer;
int out[10001] = {0};

void rec(int cnt) {
    if (cnt == M) {
        for (int item: answer) {
            cout << item << ' ';
        }
        cout << '\n';
        return;
    }
    for (auto ptr = arr.begin(); ptr != arr.end(); ++ptr) {
        if (out[*ptr]) {
            continue;
        }
        answer.push_back(*ptr);
        out[*ptr] = 1;
        rec(cnt + 1);
        answer.pop_back();
        out[*ptr] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end());
    rec(0);

    return 0;
}