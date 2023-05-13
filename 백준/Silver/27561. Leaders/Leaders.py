import sys

input = sys.stdin.readline

n = int(input())
breeds = list(input().rstrip())
range_list = list(map(int, input().split()))
t_leader = {"G": -1, "H": -1}
leader_c = {"G": 0, "H": 0}

breeds_visited = {"G": False, "H": False}

for i in range(n):
    breed = breeds[i]
    if breeds[i] == breed and not breeds_visited[breed]:
        breeds_visited[breed] = True
        flag = True
        if range_list[i] < n:
            for j in range(range_list[i], n):
                if breeds[j] == breed:
                    flag = False
                    break
        if flag:
            t_leader[breed] = i
            leader_c[breed] += 1

    if breeds_visited["G"] and breeds_visited["H"]:
        break

for i in range(n):
    r = range_list[i]
    breed = "G" if breeds[i] == "H" else "H"
    if t_leader[breed] != -1 and i < t_leader[breed] < r:
        leader_c[breeds[i]] += 1

print(leader_c["G"]* leader_c["H"])
