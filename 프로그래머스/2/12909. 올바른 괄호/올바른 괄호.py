def solution(s):
    stack = [s[0]]
    
    for cur in s[1:]:
        if cur == '(':
            stack.append(cur)
        elif stack and stack[-1] == '(':
            stack.pop()
        else:
            return False
            
    return not len(stack)