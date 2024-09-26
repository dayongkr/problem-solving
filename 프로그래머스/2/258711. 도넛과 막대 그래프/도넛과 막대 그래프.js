
// O(N) 으로 해결
// 2개 이상 나갔는데 들어오는 게 없는 정점이 시작
// 해당 정점 찾고 각 정점들을 탐색해서 패턴 찾기
// 패턴:
// 도넛 - 나가는 간선과 돌아오는 관선 하나씩 순환 O
// 막대 - 그냥 앞으로 나아가기만 함 순환 X
// 8자 - 탐색하다가 나가는 간선이 2개 인 얘가 있으면 8자

// edges로 인접 리스트 만들기
// set을 사용해 들어오는 정점 없는 거 찾기
// 생성 정점을 기준으로 하나씩 나아가며 패턴 파악
// 탐색하다가 더 이상 갈데가 없으면 -> 막대
// 탐색하다가 간선이 2개 이상이면 -> 8자
// 다 탐색했는데 또 가려고하면 -> 도넛

function solution(edges) {
    const list = new Array(1e6 + 1)
    const hasInDegree = new Set()
    let size = 0, start = 0
    

    for (let i = 0; i < edges.length; i++) {
        const [from, to] = edges[i]
        
        if (list[from] === undefined) {
            list[from] = [to]
        } else {
            list[from].push(to)
        }
        
        size = Math.max(size, Math.max(from, to))
        
        hasInDegree.add(to)
    }
    
    for (let i = 1; i <= size; i++) {
        if (hasInDegree.has(i)) {
            continue
        }
        
        if (list[i] && list[i].length >= 2) {
            start = i
            break
        }
    }
    
    const result = [start, 0, 0, 0]
    
    for (let i = 0; i < list[start].length; i++) {
        const to = list[start][i];
        const type = getType(to, list)
        
        result[type] += 1
    }
    
    return result
}

function getType(node, list) {
    stack = [node]
    visited = new Set(stack)
    
    while (stack.length) {
        const cur = stack.pop()
        const length = list[cur] ? list[cur].length : 0
        
        if (length === 2) {
            return 3
        }
        
        for (let i = 0; i < length; i++) {
            const next = list[cur][i]
            
            if (visited.has(next)) {
                return 1
            }
            
            stack.push(next)
        }
    }
    
    return 2
}
