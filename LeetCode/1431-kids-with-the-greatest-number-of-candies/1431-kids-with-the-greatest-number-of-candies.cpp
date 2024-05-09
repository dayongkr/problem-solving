class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int MAX = 0;
        for (int candy : candies)
            MAX = max(candy, MAX);
        vector<bool> result;
        for (int candy : candies)
            result.push_back(candy + extraCandies >= MAX);
        return result;
    }
};