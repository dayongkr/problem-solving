#include <iostream>

using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAX = 2000;
const int BASE_ROW = 37, BASE_COL = 5831;

ll row_hash[MAX][MAX], final_hash[MAX][MAX];
char temp[MAX + 1];

ll mod(ll a) {
    if (a >= 0) return a % MOD;
    else return ((-a / MOD + 1) * MOD + a) % MOD;
}

void row_hashing(string s, int W, int M, int lines) {
    ll power = 1, temp_hash = 0;
    for (int i = 0; i <= M - W; i++) {
        if (i == 0) {
            for (int j = 0; j < W; j++) {
                temp_hash = mod(mod(temp_hash * BASE_ROW) + s[j]);
                if (j != W - 1) power = mod(power * BASE_ROW);
            }
        } else
            temp_hash = mod(mod(BASE_ROW * (temp_hash - mod(power * s[i - 1]))) + s[i + W - 1]);
        row_hash[lines][i] = temp_hash;
    }
}

void col_hashing(int H, int W, int N, int M) {
    for (int i = 0; i <= M - W; i++) {
        ll power = 1, temp_hash = 0;
        for (int j = 0; j <= N - H; j++) {
            if (j == 0) {
                for (int k = 0; k < H; k++) {
                    temp_hash = mod(temp_hash + mod(power * row_hash[H - k - 1][i]));
                    if (k != H - 1) power = mod(power * BASE_COL);
                }
            } else
                temp_hash = mod(mod(BASE_COL * (temp_hash - mod(power * row_hash[j - 1][i]))) +
                                row_hash[j + H - 1][i]);
            final_hash[j][i] = temp_hash;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(NULL);

    int H, W, N, M, result = 0;
    ll pattern;

    cin >> H >> W >> N >> M;

    for (int i = 0; i < H; i++) {
        cin >> temp;
        row_hashing(temp, W, W, i);
    }
    col_hashing(H, W, H, W);
    pattern = final_hash[0][0];

    for (int i = 0; i < N; i++) {
        cin >> temp;
        row_hashing(temp, W, M, i);
    }
    col_hashing(H, W, N, M);

    for (int i = 0; i <= N - H; i++)
        for (int j = 0; j <= M - W; j++)
            if (pattern == final_hash[i][j]) result++;
    cout << result << '\n';

    return 0;
}