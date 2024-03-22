#include <bits/stdc++.h>

using namespace std;

int visited[8], answer = -1, s;

void rec(int index, vector<vector<int>>& dungeons, int cnt, int life) {
    answer = max(cnt, answer);
    for(int i = 0; i< s; i++) {
        if(visited[i]) continue;
        int required = dungeons[i][0];
        if(required > life) continue;
        visited[i] = 1;
        rec(i,dungeons, cnt + 1, life - dungeons[i][1]);
        visited[i] = 0;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    s = dungeons.size();
    memset(visited,0,sizeof(visited));
    for(int i = 0; i< s; i++) {
        int required = dungeons[i][0];
        if(required > k) continue;
        visited[i] = 1;
        rec(i,dungeons, 1, k - dungeons[i][1]);
        visited[i] = 0;
    }
    return answer;
}