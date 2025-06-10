# 백준 3474 : 교수가 된 현우 (https://www.acmicpc.net/problem/3474)
import sys

t = int(sys.stdin.readline())
for _ in range(t):
    a = int(sys.stdin.readline())
    ret2, ret5 = 0, 0
    i = 2
    while i <= a:
        ret2 += a // i
        i *= 2
    i = 5
    while i <= a:
        ret5 += a // i
        i *= 5
    sys.stdout.write(str(min(ret2, ret5))+'\n')