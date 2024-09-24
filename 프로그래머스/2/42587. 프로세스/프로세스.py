from collections import deque

def solution(priorities, location):
    queue = deque(zip(priorities, range(len(priorities))))
    count = 1
    
    while queue:
        top = queue.popleft()
        
        if any (top[0] < item[0] for item in queue):
            queue.append(top)
        elif top[1] == location:
            return count
        else:
            count += 1
        
    return count
            