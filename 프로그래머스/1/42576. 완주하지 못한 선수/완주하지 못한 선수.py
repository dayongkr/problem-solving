from collections import Counter
def solution(participant, completion):
    participant_count =  Counter(participant)

    for person in completion:
        participant_count[person] -= 1
    
    for person in participant_count:
        if participant_count[person] > 0:
            return person