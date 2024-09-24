from itertools import combinations

def solution(friends, gifts):
    gifts_map = []
    friends_map = {}
    gifts_score = []
    result = []
    
    for index, friend in enumerate(friends):
        friends_map[friend] = index
        gifts_map.append([0 for _ in range(len(friends))])
        gifts_score.append(0)
        result.append(0)
        
    for gift in gifts:
        A, B = gift.split()
        A_index, B_index = friends_map[A], friends_map[B]
        
        gifts_map[A_index][B_index] += 1
        gifts_score[A_index] += 1
        gifts_score[B_index] -= 1
    
    for A_index, B_index in combinations(range(len(friends)),2):
        if A_index == B_index:
            continue
        A_gifts, B_gifts = gifts_map[A_index][B_index], gifts_map[B_index][A_index]
        A_score, B_score = gifts_score[A_index], gifts_score[B_index]

        if A_gifts > B_gifts:
            result[A_index] += 1
        elif A_gifts < B_gifts:
            result[B_index] += 1
        elif A_score > B_score:
            result[A_index] += 1
        elif A_score < B_score:
            result[B_index] += 1
    
    return max(result)