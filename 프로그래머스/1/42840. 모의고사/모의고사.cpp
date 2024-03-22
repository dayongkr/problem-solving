#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int a = 0, b = 0, c = 0, as[5] = {1, 2, 3, 4, 5}, bs[8] = {2, 1, 2, 3, 2, 4, 2, 5}, cs[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}, len = answers.size(), MAX;
    
    for (int i = 0; i< len; i++) {
        int target = answers[i];
        if(as[i % 5] == target) a++;
        if(bs[i % 8] == target) b++;
        if(cs[i % 10] == target) c++;
    }
    MAX = max(a, max(b, c));
    if(a == MAX) answer.push_back(1);
    if(b == MAX) answer.push_back(2);
    if(c == MAX) answer.push_back(3);
    return answer;
}