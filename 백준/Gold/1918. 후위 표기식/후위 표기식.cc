#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

stack<char> s;
string str;
unordered_map<char, int>
        in = {{'+', 1},
              {'-', 1},
              {'*', 10},
              {'/', 10},
              {'(', 20}},
        out = {{'+', 1},
               {'-', 1},
               {'*', 10},
               {'/', 10},
               {'(', 0}};
char t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> str;

    for (char c: str) {
        if (c >= 'A' && c <= 'Z') {
            cout << c;
        } else {
            if (c == ')') {
                while (!s.empty() && s.top() != '(') {
                    t = s.top();
                    s.pop();
                    cout << t;
                }
                s.pop();
            } else {
                while (!s.empty() && out[s.top()] >= in[c]) {
                    cout << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
    }
    while (!s.empty()) {
        t = s.top();
        s.pop();
        cout << t;
    }

    return 0;
}