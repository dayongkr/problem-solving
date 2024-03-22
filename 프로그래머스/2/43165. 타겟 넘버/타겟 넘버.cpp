#include <bits/stdc++.h>

using namespace std;

int answer = 0, length;

void rec(vector<int>& numbers, int size, int result, int target) {
    if (size == length) {
        if(target == result) answer++;
        return;
    }
    int x = numbers[size];
    rec(numbers, size + 1, result + x, target);
    rec(numbers, size + 1, result - x, target);
}

int solution(vector<int> numbers, int target) {
    length = numbers.size();
    int x = numbers[0];
    rec(numbers, 1, x, target);
    rec(numbers, 1, -x, target);
    return answer;
}