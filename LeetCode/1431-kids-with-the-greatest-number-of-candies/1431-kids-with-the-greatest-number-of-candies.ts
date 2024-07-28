function kidsWithCandies(candies: number[], extraCandies: number): boolean[] {
    const max_candies = Math.max(...candies)
    const n = candies.length;
    const result = [];
    for(const candy of candies)
        if (candy + extraCandies >= max_candies) {
            result.push(true)
        } else{
            result.push(false)
        }
    }

    return result;
};