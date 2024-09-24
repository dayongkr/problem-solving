function solution(progresses, speeds) {
    const answer = [1];
    let days = Math.ceil((100 - progresses[0]) / speeds[0])
    
    for (let i = 1; i < progresses.length; i++) {
        const progress = progresses[i], speed = speeds[i]
        
        if (progress + speed * days >= 100) {
            answer[answer.length - 1] += 1
        } else {
            answer.push(1)
            days = Math.ceil((100 - progress) / speed)
        }
    }
    
    return answer;
}