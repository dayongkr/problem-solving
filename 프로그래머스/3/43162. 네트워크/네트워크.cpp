#include <bits/stdc++.h>

using namespace std;

int visited[200];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    memset(visited, 0, sizeof(visited)); 
    for(int i = 0; i < n; i++) {
        if (visited[i]) continue;
        answer++;
        queue<int>q;
        q.push(i);
        visited[i] = 1;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            for(int j = 0; j < n; j++) {
                int t = computers[cur][j];
                if (t && !visited[j]) {
                    q.push(j);
                    visited[j] = 1;
                }
            }
        }
        
    }
    return answer;
}