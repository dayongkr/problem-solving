input()
s = set(map(int,input().split()))
input()
result = [1 if item in s else 0for item in map(int, input().split())]
print(*result)