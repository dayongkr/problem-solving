function solution(priorities, location) {
    const arr = priorities.map((_, index) => index)
    let count = 1, start = 0
    
    function shift() {
        const result = arr[start]
        
        arr[start++] = -1
        
        return result
    }
    
    while (arr) {
        const top = shift();
        
        if (arr.some(item => item !== -1 && priorities[item] > priorities[top])) {
            arr.push(top)
        } else if (top === location) {
            return count
        } else {
            count += 1
        }
    }
    
    
    return count
}