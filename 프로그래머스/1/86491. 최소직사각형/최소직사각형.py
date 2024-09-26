def solution(sizes):
    result = list(map(lambda arr: [arr[1], arr[0]] if arr[0] < arr[1] else arr, sizes))
    return max(result, key=lambda x: x[0])[0] * max(result, key=lambda x: x[1])[1]
    