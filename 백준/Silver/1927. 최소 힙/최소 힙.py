import sys

input = sys.stdin.readline

n = int(input())
heap = list()
num = 0


# min heap insert 구현
def heap_insert():
    heap.append(num)
    i = len(heap) - 1
    while i > 0:
        child = heap[i]
        parent = heap[(i - 1) // 2]
        if child < parent:
            heap[i], heap[(i - 1) // 2] = parent, child
            i = (i - 1) // 2
        else:
            break


for _ in range(n):
    num = int(input())
    if num == 0:
        if len(heap) == 0:
            print(0)
        else:
            print(heap[0])
            heap[0] = heap[-1]
            heap.pop()
            i = 0
            while i < len(heap):
                parent = heap[i]
                if i * 2 + 2 < len(heap):
                    child1 = heap[i * 2 + 1]
                    child2 = heap[i * 2 + 2]
                    if child1 < child2:
                        if child1 < parent:
                            heap[i], heap[i * 2 + 1] = child1, parent
                            i = i * 2 + 1
                        else:
                            break
                    else:
                        if child2 < parent:
                            heap[i], heap[i * 2 + 2] = child2, parent
                            i = i * 2 + 2
                        else:
                            break
                elif i * 2 + 1 < len(heap):
                    child = heap[i * 2 + 1]
                    if child < parent:
                        heap[i], heap[i * 2 + 1] = child, parent
                        i = i * 2 + 1
                    else:
                        break
                else:
                    break
    else:
        heap_insert()
