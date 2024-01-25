#include <iostream>
#include <vector>
#include <stack>
#include <cstring>

using namespace std;

char ret[401];

class Trie {
    static constexpr size_t M = 26;
    static constexpr char OFFSET = 'a';

    struct TrieNode {
        int child[M];
        bool is_terminal;

        TrieNode() {
            memset(child, -1, sizeof(int) * M);
            is_terminal = false;
        }
    };

    vector<TrieNode> nodes;

public:
    Trie() : nodes(1) {}

    void init() {
        nodes.resize(1);
        nodes[0] = TrieNode();
    }

    void insert(const string &s) {
        int cur = 0;
        for (char ch: s) {
            if (nodes[cur].child[ch - OFFSET] == -1) {
                nodes[cur].child[ch - OFFSET] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].child[ch - OFFSET];
        }
        nodes[cur].is_terminal = true;
    }

    void get_k_string(int k) {
        stack<pair<int, pair<int, int>>> st;
        st.emplace(0, make_pair(-1, -1));
        while (!st.empty()) {
            int cur = st.top().first, ch = st.top().second.first, depth = st.top().second.second;
            if (ch != -1)
                ret[depth] = ch + OFFSET;

            st.pop();
            if (nodes[cur].is_terminal) {
                if (--k == 0) {
                    ret[depth + 1] = '\0';
                    return;
                }
            }
            for (int i = M - 1; i >= 0; --i) {
                if (nodes[cur].child[i] != -1) {
                    st.emplace(nodes[cur].child[i], make_pair(i, depth + 1));
                }
            }
        }
        strcpy(ret, "none");
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(NULL);
    int test_case, T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case) {
        int K;
        string s;
        cin >> K >> s;
        Trie trie;
        trie.init();
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                trie.insert(s.substr(i, j - i + 1));
            }
        }
        trie.get_k_string(K);
        cout << '#' << test_case << ' ' << ret << '\n';
    }
    return 0;
}