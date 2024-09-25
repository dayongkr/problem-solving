function solution(array, commands) {
    const result = new Array(commands.length)
    for (let index = 0; index < commands.length; index++) {
        const [i, j, k] = commands[index]
        result[index] = array.slice(i - 1, j).sort((a, b) => a - b)[k - 1]
    }
    return result
}