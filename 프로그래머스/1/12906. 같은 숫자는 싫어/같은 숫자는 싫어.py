def solution(arr):
    answer = [arr[0]]
    
    for item in arr[1:]:
        if answer[-1] != item:
            answer.append(item)
        
    
    return answer