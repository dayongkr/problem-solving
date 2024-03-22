#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<>> pq;
    for(auto s: scoville) pq.push(s);
    int answer = 0;
    while(!pq.empty()) {
        int first = pq.top(); pq.pop();
        if(first >= K) return answer;
        if(!pq.empty()){
            int second = pq.top(); pq.pop();
            answer++;
            pq.push(first + second * 2);
        }
    }
    return -1;
}