#include <iostream>
using namespace std;

int r1 = 0;

int rec(int n) {
    if (n == 1 || n == 2){
        r1 += 1;
        return 1;
    }
    return rec(n-1) + rec(n-2);
}

int main() {
    int n, r2;
    cin >> n;
    r2 = n - 2;
    rec(n);
    cout << r1 << " " << r2;

    return 0;
}