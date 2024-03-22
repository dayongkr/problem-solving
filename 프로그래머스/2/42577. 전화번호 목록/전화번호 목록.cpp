#include <bits/stdc++.h>

using namespace std;

struct Node {
    int child[10];
    bool is_terminal;
    
    Node() {
        memset(child, -1, sizeof(child));
        is_terminal = false;
    }
};

vector<Node> nodes;

bool insert(string str) {
    int cur = 0, str_len = str.size();
    for(int i = 0; i < str_len; i++) {
        int c = str[i] - '0';
        if(nodes[cur].child[c] == -1) {
            nodes[cur].child[c] = nodes.size();
            nodes.emplace_back();
        } else if(i == str_len - 1) return true;
        cur = nodes[cur].child[c];
        if(nodes[cur].is_terminal) return true;
    }
    nodes[cur].is_terminal = true;
    return false;
}

bool solution(vector<string> phone_book) {
    nodes.emplace_back();
    for(auto str: phone_book) {
        if(insert(str)) return false;
    }
    return true;
}