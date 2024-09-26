function solution(sizes) {
    let [max_w, max_h] = [0, 0]
    
    for (let i = 0; i < sizes.length; i++) {
        let [w, h] = sizes[i]
        
        if (w < h) {
            const temp = w
            w = h
            h = temp
        }
        
        max_w = Math.max(max_w, w)
        max_h = Math.max(max_h, h)
    }
    return max_w * max_h
}