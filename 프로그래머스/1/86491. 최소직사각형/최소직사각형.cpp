#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int MAX_W=0, MAX_H=0;
    for (auto size: sizes) {
        if(size[0] < size[1]) swap(size[0],size[1]);
        MAX_W = max(size[0], MAX_W);
        MAX_H = max(size[1], MAX_H);
    }
    answer = MAX_W * MAX_H;
    return answer;
}