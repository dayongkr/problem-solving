function kidsWithCandies(candies: number[], extraCandies: number): boolean[] {
    let max_candies = 0;
    const n = candies.length;
    const result:boolean[] = Array.from({ length: n }, () => false)

    for (const candy of candies) {
        max_candies = Math.max(max_candies, candy)
    }

    for (let i = 0; i < n; i++) {
        if (candies[i] + extraCandies >= max_candies) {
            result[i] = true
        }
    }
    return result;
};