#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> s;
    int answer = 0;
    for(auto num : nums) {
        s.emplace(num);
    }
    answer = s.size() > nums.size() / 2 ? nums.size() / 2 : s.size();
    return answer;
}