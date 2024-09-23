function solution(clothes) {
    const count = new Map()
    
    for (const [_, type] of clothes) {
        count.set(type, (count.get(type) ?? 0) + 1)
    }
    
    let result = 1
    
    for (const value of count.values()) {
        result *= value + 1
    }

    return result - 1
}