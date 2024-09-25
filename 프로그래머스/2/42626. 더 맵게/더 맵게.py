import heapq

def solution(scoville, K):
    heapq.heapify(scoville)
    result = 0
    
    while scoville:
        first = heapq.heappop(scoville)
        
        if first >= K:
            return result
        
        if scoville:
            heapq.heappush(scoville, first + heapq.heappop(scoville) * 2)
            result += 1
            
    return -1
