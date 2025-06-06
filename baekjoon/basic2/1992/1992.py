# 백준 1992 : 쿼드트리 (https://www.acmicpc.net/problem/1992)

import sys
sys.setrecursionlimit(10**6)

def go(y, x, n):
    if n == 1: return str(a[y][x])
    ret = ""
    for i in range(y, y+n):
        for j in range(x, x+n):
            if a[i][j] != a[y][x]:
                ret += ("("+go(y, x, n//2)+go(y, x+n//2, n//2)+go(y+n//2, x, n//2)+go(y+n//2,x+n//2,n//2)+")")
                return ret
    return str(a[y][x])

n = int(sys.stdin.readline())
a = []
for i in range(n):
    a.append(list(map(int, sys.stdin.readline().rstrip())))
sys.stdout.write(go(0,0,n)+"\n")