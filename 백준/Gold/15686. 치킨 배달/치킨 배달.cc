#include <iostream>
#include <vector>

using namespace std;

int N, M, temp, visited[13] = {0}, final = 1e9;
vector<pair<int, int>> shop, home;

int getDistance() {
    int result = 0;
    for (auto item: home) {
        int min_d = 1e9;
        for (int i = 0; i < shop.size(); i++)
            if (visited[i]) {
                min_d = min(min_d, abs(item.first - shop[i].first) + abs(item.second - shop[i].second));
            }
        result += min_d;
    }
    return result;
}

void rec(int s,int cnt) {
    if (cnt == M) {
        final = min(final, getDistance());
        return;
    }
    for (int i = s+1; i < shop.size(); i++) {
        if (!visited[i]) {
            visited[i] = 1;
            rec(i,cnt + 1);
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> temp;
            if (temp == 1) home.emplace_back(i, j);
            else if (temp == 2) shop.emplace_back(i, j);
        }
    for (int i = 0; i < shop.size(); i++) {
        visited[i] = 1;
        rec(i,1);
        visited[i] = 0;
    }
    cout << final;
    return 0;
}