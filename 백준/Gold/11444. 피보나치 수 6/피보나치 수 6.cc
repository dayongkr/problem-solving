#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;
typedef vector<vector<ll>> matrix;
#define MAX 1000000007

matrix result = {{1, 0},
                 {0, 1}}, a = {{1, 1},
                               {1, 0}};
ll N;

matrix mul(matrix &x, matrix &y) {
    matrix mat(2, vector<ll>(2));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++)
                mat[i][j] += x[i][k] * y[k][j];
            mat[i][j] %= MAX;
        }
    return mat;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    cin >> N;
    while (N > 0) {
        if (N % 2 == 1)
            result = mul(result, a);
        a = mul(a, a);
        N /= 2;
    }
    cout << result[0][1];

    return 0;
}