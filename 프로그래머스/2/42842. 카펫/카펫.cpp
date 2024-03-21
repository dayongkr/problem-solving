#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int target = brown + yellow;
    for(int i = 1; i <= yellow; i++) {
        if(yellow % i != 0) continue;
        int width = yellow / i + 2, height = i + 2;
        if(width * height == target){
            if (width < height) swap(width, height);
            answer.push_back(width);
            answer.push_back(height);
            break;
        }
        
    }
    return answer;
}