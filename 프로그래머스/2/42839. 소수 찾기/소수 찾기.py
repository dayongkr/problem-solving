result = []

def rec(index, numbers, used, made):
    made.append(numbers[index])
    used[index] = 1
    num = int("".join(made))
    can = True
    for i in range(2, num):
        if num % i == 0:
            can = False
            break
    if num != 0 and num != 1 and can:
        result.append(num)
    
    for i in range(len(numbers)):
        if not used[i]: 
            rec(i, numbers, used, made)
    used[index] = 0
    made.pop()
    
def solution(numbers):
    used = [0] * len(numbers)
    made = []
    for i in range(len(numbers)):
        rec(i, numbers, used, made)
    print(result)
    answer = len(set(result))
    return answer