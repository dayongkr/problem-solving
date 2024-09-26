def solution(name):
    answer = 0
    N = len(name)
    move = N - 1
    
    for i in range(N):
        cur_ascii = ord(name[i])
        answer += min(cur_ascii - 65, 91 - cur_ascii)
        j = i + 1
        
        while j < N and name[j] == 'A':
            j += 1
        
        move = min(move, i * 2 + N - j, (N - j) * 2 + i)
    
    return answer + move

