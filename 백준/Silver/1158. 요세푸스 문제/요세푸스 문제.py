import sys

input = sys.stdin.readline

N, K = map(int, input().split())


class Node:
    def __init__(self, value=None, prev=None, next=None):
        self.value = value
        self.prev = prev
        self.next = next


def insert(node, value):
    nextNode = node.next
    node.next = Node(value, node, nextNode)

    if nextNode:
        nextNode.prev = node.next

    return node.next


def erase(node):
    nextNode = node.next
    node.prev.next = nextNode

    if nextNode:
        nextNode.prev = node.prev

    return node.prev


head = Node(1)
cursor = head

for i in range(2, N + 1):
    cursor = insert(cursor, i)

cursor.next = head
head.prev = cursor

print('<', end='')

for i in range(N):
    for _ in range(K):
        cursor = cursor.next
    print(cursor.value, end='')
    if i != N - 1:
        print(', ', end='')
    cursor = erase(cursor)

print('>')
