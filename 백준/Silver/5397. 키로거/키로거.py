import sys

input = sys.stdin.readline

N = int(input())


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


for _ in range(N):
    logger = list(input().rstrip())
    head = Node()
    cursor = head

    for char in logger:
        if char == '<':
            cursor = cursor.prev if cursor.prev else cursor
        elif char == '>':
            cursor = cursor.next if cursor.next else cursor
        elif char == '-':
            cursor = erase(cursor) if cursor.value else cursor
        else:
            cursor = insert(cursor, char)

    while head:
        if head.value:
            print(head.value, end="")
        head = head.next
    print()
