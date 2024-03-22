#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int s = progresses.size();
    for(int i =0; i< s; i++) {
        q.push((100 - progresses[i] + speeds[i] - 1) / speeds[i]);
    }
    int now = q.front(), cnt = 1;
    q.pop();
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur <= now) cnt++;
        else {
            answer.push_back(cnt);
            now = cur;
            cnt = 1;
        }
    }
    answer.push_back(cnt);
    return answer;
}