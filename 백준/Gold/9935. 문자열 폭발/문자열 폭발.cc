#include <iostream>
#include <vector>
#include <string>


using namespace std;

string str, boom;
vector<char> s;

void input() {
    cin >> str >> boom;
}

void solve() {
    for (char c: str) {
        s.push_back(c);
        if (c == boom.back()) {
            auto it_s = s.end() - 1;
            auto it_b = boom.end() - 1;
            int cnt = 0;
            size_t boom_len = boom.length();
            while (*it_s == *it_b && cnt != boom_len) {
                cnt++;
                it_s--;
                it_b--;
            }
            if (cnt == boom_len) s.erase(it_s + 1, s.end());
        }
    }
    if (s.empty())
        cout << "FRULA";
    else for (auto c: s) cout << c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    input();
    solve();
    return 0;
}