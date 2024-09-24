from collections import deque

def getMax(queue):
    result = queue[0][0]
    
    for item in queue:
        if result < item[0]:
            result = item[0]
    
    return result

def solution(priorities, location):
    queue = deque(zip(priorities, range(len(priorities))))
    count = 1
    
    while queue:
        top = queue.popleft()
        
        if queue and top[0] < getMax(queue):
            queue.append(top)
        elif top[1] == location:
            return count
        else:
            count += 1
        
    return count
            