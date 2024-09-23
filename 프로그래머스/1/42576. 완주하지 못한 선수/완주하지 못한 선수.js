function solution(participant, completion) {
    const count = new Map()
    
    for (const person of participant) {
        if (count.has(person)){
            count.set(person, count.get(person) + 1)
        } else {
            count.set(person, 1)
        }
    }
    
    for (const person of completion) {
        count.set(person, count.get(person) - 1)
    }
    
    
    for (const [key, value] of count) {
        if (value > 0) {
            return key
        }
    }
}