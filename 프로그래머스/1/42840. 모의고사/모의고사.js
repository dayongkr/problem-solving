function solution(answers) {
    const first = [1,2,3,4,5]
    const second = [2,1,2,3,2,4,2,5]
    const third = [3,3,1,1,2,2,4,4,5,5]
    
    const corrected_first = answers.filter((answer, index) => answer === first[index % 5])
    const corrected_second = answers.filter((answer, index) => answer === second[index % 8])
    const corrected_third = answers.filter((answer, index) => answer === third[index % 10])
    
    const max = Math.max(corrected_first.length, corrected_second.length, corrected_third.length)
    
    const result = []
    
    if (corrected_first.length === max) {
        result.push(1)
    }
    
    if (corrected_second.length === max) {
        result.push(2)
    }
    
    if (corrected_third.length === max) {
        result.push(3)
    }
    return result;
}