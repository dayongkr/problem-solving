function kidsWithCandies(candies: number[], extraCandies: number): boolean[] {
    const max_candies = Math.max(...candies)
    const n = candies.length;
    const result = [];

    for (let i = 0; i < n; i++) {
        if (candies[i] + extraCandies >= max_candies) {
            result.push(true)
        } else{
            result.push(false)
        }
    }

    return result;
};