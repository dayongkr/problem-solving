function mergeAlternately(word1: string, word2: string): string {
    let p1 = 0, p2 = 0, result = ""
    const N = word1.length, M = word2.length

    while (p1 < N && p2 < M) {
        result += word1[p1++]
        result += word2[p2++]
    }
    if (p1 < N) result += word1.substring(p1)
    if (p2 < M) result += word2.substring(p2)
    return result
};