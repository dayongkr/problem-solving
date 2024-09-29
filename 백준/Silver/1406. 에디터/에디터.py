import sys

input = sys.stdin.readline

string = input().rstrip()
M = int(input())


class Node:
    def __init__(self, value=None, prev=None):
        self.value = value
        self.next = None
        self.prev = prev


def insert(node, value):
    temp = node.next
    node.next = Node(value, node)

    if temp:
        temp.prev = node.next

    node.next.next = temp

    return node.next


def erase(node):
    nextNode = node.next
    node = node.prev
    node.next = nextNode

    if nextNode:
        nextNode.prev = node

    return node


head = Node()
cursor = head

for c in string:
    cursor.next = Node(c, cursor)
    cursor = cursor.next


for _ in range(M):
    command = input().rstrip().split()

    if command[0] == 'L' and cursor.prev:
        cursor = cursor.prev
    elif command[0] == 'D' and cursor.next:
        cursor = cursor.next
    elif command[0] == 'B' and cursor.prev:
        cursor = erase(cursor)
    elif command[0] == 'P':
        cursor = insert(cursor, command[1])

while head:
    if head.value:
        print(head.value, end='')
    head = head.next
