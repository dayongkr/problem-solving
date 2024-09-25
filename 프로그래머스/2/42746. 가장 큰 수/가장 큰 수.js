function solution(numbers) {
    const result = numbers.map(String).sort((a,b) => {
        if (a + b > b + a) {
            return -1;
        }
        
        if (a + b < b + a) {
            return 1
        }
        
        return 0
    }).join('')
    
    if (result[0] === '0') {
        return '0'
    }
    
    return result
}