function canPlaceFlowers(flowerbed: number[], n: number): boolean {
    const length = flowerbed.length;

    for (let i = 0; i < length; i++) {
        if (!flowerbed[i] &&
            (i + 1 >= length || !flowerbed[i + 1]) &&
            (i - 1 < 0 || !flowerbed[i - 1])) {
            flowerbed[i] = 1;
            n--;
        }
        if (n <= 0) return true
    }
    return false
};