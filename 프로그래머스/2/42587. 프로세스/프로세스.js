function solution(priorities, location) {
    const arr = priorities.map((priority, index) => [priority, index]);
    let count = 1, start = 0
    
    function shift() {
        const result = arr[start].slice()
        
        arr[start++][0] = 0
        
        return result
    }
    
    while (arr) {
        const top = shift();
        if (arr.some(item => item[0] > top[0])) {
            arr.push(top)
        } else if (top[1] === location) {
            return count
        } else {
            count += 1
        }
    }
    
    
    return count
}