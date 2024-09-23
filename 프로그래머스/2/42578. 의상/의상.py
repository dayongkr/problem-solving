def solution(clothes):
    clothes_dict = {}
    
    for name, type in clothes:
        if type in clothes_dict:
            clothes_dict[type] += 1
        else:
            clothes_dict[type] = 1
    
    result = 1
    
    for key in clothes_dict:
        result *= clothes_dict[key] + 1
    
    return result - 1