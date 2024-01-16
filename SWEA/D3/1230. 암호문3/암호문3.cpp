#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case, T = 10, N, M;
    vector<int> v;

    for (test_case = 1; test_case <= T; ++test_case) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        cin >> M;

        for (int i = 0; i < M; i++) {
            char type;
            int x, y, s;
            cin >> type;

            if (type == 'A') {
                cin >> y;
                for (int j = 0; j < y; j++) {
                    cin >> s;
                    v.push_back(s);
                }
            } else {
                cin >> x >> y;
                auto it = v.begin() + x;
                if (type == 'I') {
                    for (int j = 0; j < y; j++) {
                        cin >> s;
                        v.insert(it, s);
                        it++;
                    }
                } else {
                    v.erase(it, it + y);
                }
            }
        }

        int print_size = min(10, (int) v.size());
        cout << "#" << test_case;
        for (int i = 0; i < print_size; i++) {
            cout << " " << v[i];
        }
        cout << '\n';
    }
    return 0;
}