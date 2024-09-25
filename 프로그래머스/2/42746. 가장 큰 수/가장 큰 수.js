function solution(numbers) {
    const result = numbers.map(String).sort((a,b) => Number(b + a) - Number(a + b)).join('')
    
    return result[0] === '0' ? '0' : result
}