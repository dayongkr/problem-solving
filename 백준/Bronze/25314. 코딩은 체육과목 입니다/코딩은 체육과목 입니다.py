import sys
input = sys.stdin.readline

byte = int(input())

print("long " * int(byte/4) + "int")