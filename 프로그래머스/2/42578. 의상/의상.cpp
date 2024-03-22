#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<string>> clothes) {
    vector<string> s;
    unordered_map<string, int> m;
    for(auto cloth: clothes){
        if(!m.count(cloth[1])){
            s.push_back(cloth[1]);
            m.emplace(cloth[1], 1);
        }
        else
            m[cloth[1]]++;
    }
    int answer = 1;
    for(auto key: s) 
        answer *= m[key] + 1;
    return answer - 1;
}