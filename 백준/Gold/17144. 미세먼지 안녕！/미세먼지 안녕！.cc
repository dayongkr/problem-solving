#include <iostream>
#include <vector>

using namespace std;

int R, C, T, arr[50][50], dr[4] = {0, -1, 0, 1}, dc[4] = {1, 0, -1, 0},
        dr_rev[4] = {0, 1, 0, -1}, dc_rev[4] = {1, 0, -1, 0};
vector<pair<int, int>> air_conditioner;


void input() {
    cin >> R >> C >> T;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            int temp;
            cin >> temp;
            if (temp == -1) air_conditioner.emplace_back(i, j);
            arr[i][j] = temp;
        }
}

void runAirConditioner() {
    int top_r = air_conditioner.front().first, top_c = air_conditioner.front().second,
            bottom_r = air_conditioner.back().first, bottom_c = air_conditioner.back().second,
            temp = 0, temp2, TOP_R = top_r, TOP_C = top_c, BOTTOM_R = bottom_r, BOTTOM_C = bottom_c;
    for (int i = 0; i < 4; i++) {
        int nr = top_r + dr[i], nc = top_c + dc[i];
        while (nr >= 0 && nr < R && nc >= 0 && nc < C && !(nr == TOP_R && nc == TOP_C)) {
            top_r = nr, top_c = nc;
            temp2 = arr[nr][nc];
            arr[nr][nc] = temp;
            temp = temp2;
            nr += dr[i], nc += dc[i];
        }
    }
    temp = 0;
    for (int i = 0; i < 4; i++) {
        int nr = bottom_r + dr_rev[i], nc = bottom_c + dc_rev[i];
        while (nr >= 0 && nr < R && nc >= 0 && nc < C && !(nr == BOTTOM_R && nc == BOTTOM_C)) {
            bottom_r = nr, bottom_c = nc;
            temp2 = arr[nr][nc];
            arr[nr][nc] = temp;
            temp = temp2;
            nr += dr_rev[i], nc += dc_rev[i];
        }
    }
}

void spreadDust() {
    vector<pair<pair<int, int>, int>> dust;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++) {
            int cur = arr[i][j];
            if (arr[i][j] > 0)dust.push_back({{i, j}, cur});
        }
    for (auto item: dust) {
        int spread_value = (int) (item.second / 5), spread_cnt = 0;
        for (int i = 0; i < 4; i++) {
            int nr = item.first.first + dr[i], nc = item.first.second + dc[i];
            if (nr >= 0 && nr < R && nc >= 0 && nc < C && arr[nr][nc] != -1) {
                spread_cnt += 1;
                arr[nr][nc] += spread_value;
            }
        }
        arr[item.first.first][item.first.second] -= spread_value * spread_cnt;
    }
}

int getDustAmount() {
    int amount = 0;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (arr[i][j] > 0) amount += arr[i][j];
    return amount;
}

void solve() {
    for (int i = 0; i < T; i++) {
        spreadDust();
        runAirConditioner();
    }
    cout << getDustAmount();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    return 0;
}