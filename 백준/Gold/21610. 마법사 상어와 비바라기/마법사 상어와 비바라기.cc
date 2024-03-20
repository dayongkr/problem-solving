#include <bits/stdc++.h>

using namespace std;

int adjust(int N, int a) {
    if (a < 0) {
        a = -a % N;
        if (a == 0) return 0;
        else return N - a;
    } else {
        a %= N;
        return a;
    }
}

int main() {
    int N, M, A[50][50], direction[8][2] = {
            {-1, 0},
            {-1, -1},
            {0,  -1},
            {1,  -1},
            {1,  0},
            {1,  1},
            {0,  1},
            {-1, 1}
    },
            diagonal[4][2] = {
            {-1, 1},
            {-1, -1},
            {1,  -1},
            {1,  1}
    },
            result = 0, time = 0;

    vector<pair<int, int>> cloud[2]; // {0, 1} = x: 0, y: 1

    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            result += A[i][j];
        }

    cloud[time].emplace_back(0, N - 1);
    cloud[time].emplace_back(1, N - 1);
    cloud[time].emplace_back(0, N - 2);
    cloud[time].emplace_back(1, N - 2);

    for (int i = 0; i < M; i++) {
        int d, s, tx, ty;
        cin >> d >> s;
        d -= 1;
        tx = direction[d][0] * s;
        ty = direction[d][1] * s;
        time = !time;
        cloud[time].clear(); // clear current cloud
        for (auto &[x, y]: cloud[!time]) { // use prev cloud
            x += tx; // move all clouds
            y += ty;
            if (x < 0 || x >= N) x = adjust(N, x); // adjust position
            if (y < 0 || y >= N) y = adjust(N, y);
            A[y][x]++; // increase 1
            result++;
        }
        for (auto [x, y]: cloud[!time]) {
            for (auto &j: diagonal) { // check diagonal
                int nx = x + j[0], ny = y + j[1];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N && A[ny][nx]) {
                    A[y][x]++;
                    result++;
                }
            }
        }

        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++) {
                int can = 1;
                if (A[j][k] < 2) continue;
                for (auto [xx, yy]: cloud[!time]) {
                    if (xx == k && yy == j) {
                        can = 0;
                        break;
                    }
                }
                if (can) {
                    A[j][k] -= 2;
                    result -= 2;
                    cloud[time].emplace_back(k, j);
                }
            }
    }

    cout << result;
    return 0;
}