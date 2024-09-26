def solution(n, lost, reserve):
    set_lost = set(lost)
    set_reserve = set(reserve)
    intersection = set_lost.intersection(set_reserve)
    
    lost = list(set_lost - intersection)
    reserve = list(set_reserve - intersection)
    
    lost.sort()
    reserve.sort()
    
    ptr = 0
    
    for l in lost:
        while ptr < len(reserve):
            diff = l - reserve[ptr]
            
            if diff >= -1:
                ptr += 1
            
            if 1 >= diff >= -1:
                n += 1
                
            if diff <= 1:
                break
                
    return n - len(lost)