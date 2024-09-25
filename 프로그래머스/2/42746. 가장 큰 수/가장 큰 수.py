from functools import cmp_to_key

def solution(numbers):
    result = "".join(sorted(map(str, numbers), key=cmp_to_key(lambda a, b: int(b + a) - int(a + b))))
    return '0' if result[0] == '0' else result