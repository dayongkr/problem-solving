#include <bits/stdc++.h>

using namespace std;

vector<int> graph[20001];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, MAX= 0;
    for (auto e: edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> pq;
    int dist[20001];
    fill(dist, dist + 20001, INT32_MAX);
    pq.emplace(0,1);
    dist[1] = 0;
    while(!pq.empty()) {
        auto [cur_dist, cur] = pq.top();
        pq.pop();
        if(cur_dist < dist[cur] ) continue;
        for(auto next: graph[cur]) {
            int next_dist= cur_dist + 1;
            if(next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.emplace(next_dist, next);
            }
        }
    }
    for(int i = 2; i<=n; i++) {
        int t = dist[i];
        cout << dist[i]<<", ";
        if(t > MAX) {answer = 1; MAX = t;}
        else if(t == MAX) answer++;
    }
    return answer;
}