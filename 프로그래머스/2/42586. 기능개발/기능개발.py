from math import ceil

def solution(progresses, speeds):
    answer = [1]
    days = ceil((100 - progresses[0]) / speeds[0])
    
    for progress, speed in zip(progresses[1:], speeds[1:]):
        if progress + speed * days >= 100:
            answer[-1] += 1
        else:
            answer.append(1)
            days = ceil(100 - progress) / speed
    
    return answer