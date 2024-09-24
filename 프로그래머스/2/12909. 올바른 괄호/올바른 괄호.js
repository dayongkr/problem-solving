function solution(s){
    const stack = [s[0]]

    for (let i = 1; i < s.length; i++) {
        const cur = s[i]
        
        if (cur === '(') {
            stack.push(cur)
        } else if(stack.at(-1) === '(') {
            stack.pop()
        } else {
            return false
        }
    }
    
    return !stack.length
}