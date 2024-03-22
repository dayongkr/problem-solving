#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int s = citations.size(), answer = 0, p =0;
    for(int i = 0; i <= 1000; i++) {
        while(i > citations[p]) p++;
        cout << p << '\n';
        if(s - p >= i) answer = i;
    }
    return answer;
}