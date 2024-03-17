#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, temp, students[401][5], a[20][20] = {0,}, map[401], result = 0,
            dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    cin >> N;
    temp = N * N;
    for (int i = 0; i < temp; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> students[i][j];
        }
        map[students[i][0]] = i;
    }
    for (int i = 0; i < temp; i++) {
        int max_empty = 0, max_favorite = 0, max_y = -1, max_x = -1;
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (a[j][k]) continue;
                int temp_empty = 0, temp_favorite = 0;
                for (int z = 0; z < 4; z++) {
                    int nx = k + dx[z], ny = j + dy[z];
                    if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                        int target = a[ny][nx];
                        if (!target) temp_empty++;
                        else
                            for (int p = 1; p < 5; p++) {
                                if (target == students[i][p]) temp_favorite++;
                            }
                    }
                }
                if ((max_favorite < temp_favorite) || (max_favorite == temp_favorite && max_empty < temp_empty)) {
                    max_empty = temp_empty;
                    max_favorite = temp_favorite;
                    max_y = j;
                    max_x = k;
                } else if (max_y == -1 && max_x == -1) {
                    max_y = j;
                    max_x = k;
                }
            }
        }
        a[max_y][max_x] = students[i][0];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int like = 1, student = a[i][j];
            for (int k = 0; k < 4; k++) {
                int nx = j + dx[k], ny = i + dy[k];
                if (nx >= 0 && nx < N && ny >= 0 && ny < N) {
                    {
                        int target = a[ny][nx];
                        for (int z = 1; z < 5; z++) {
                            if (students[map[student]][z] == target) like *= 10;
                        }
                    }
                }
            }
            result += like / 10;
        }
    }
    cout << result;
    return 0;
}