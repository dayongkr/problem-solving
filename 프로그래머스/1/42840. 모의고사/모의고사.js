function solution(answers) {
    const answer = [[1,2,3,4,5], [2,1,2,3,2,4,2,5], [3,3,1,1,2,2,4,4,5,5]]
    
    const count = [0, 0, 0]
    let result = []
    let max = 0
    
    for (let i = 0; i < answers.length; i++) {
        for (let j = 0; j < 3; j++) {
            if (answer[j][i % answer[j].length] === answers[i]) {
                count[j] += 1
            }
        }
    }
    
    for (let i = 0; i < 3; i++) {
        if (count[i] > max) {
            max = count[i]
            result = [i + 1]
        } else if (count[i] === max) {
            result.push(i + 1)
        }
    }
    
    return result;
}