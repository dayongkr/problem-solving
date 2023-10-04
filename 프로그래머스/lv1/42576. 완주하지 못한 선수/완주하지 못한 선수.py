def solution(participant, completion):
    hash = {}
    for person in participant:
        if person in hash:
            hash[person] +=1
        else:
            hash[person] = 1
    
    for person in completion:
        if person in hash:
            hash[person] +=1
        else:
            hash[person] = 1
    for key in hash:
        if hash[key] % 2 != 0:
            return key