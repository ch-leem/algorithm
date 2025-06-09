# 백준 10709 : 기상캐스터 (https://www.acmicpc.net/problem/10709)
import sys
sys.setrecursionlimit(10**6)

def go(y, x, min):
    ret[y][x] = str(min)
    if x == (w-1):
        return
    go(y, x+1, min+1)

h, w = map(int, sys.stdin.readline().split())
a = []
for i in range(h):
    a.append(list(sys.stdin.readline().rstrip()))

ret = [['-1'] * w for _ in range(h)]

for i in range(h):
    for j in range(w):
        if a[i][j] == 'c':
            go(i, j, 0)

for i in range(h):
    sys.stdout.write(' '.join(ret[i])+'\n')