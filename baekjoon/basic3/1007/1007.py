# 백준 1007 : 벡터 매칭 (https://www.acmicpc.net/problem/1007)
import sys
import math
from itertools import combinations
sys.setrecursionlimit(10**6)

def dfs(idx, cnt, sum_x, sum_y):
    global min_ret

    if cnt == n / 2:
        ox = total_x - sum_x
        oy = total_y - sum_y
        min_ret = min(min_ret, math.sqrt((sum_x - ox)**2 + (sum_y - oy)**2))
        return

    if idx == n:
        return 

    dfs(idx+1, cnt+1, sum_x + arr[idx][0], sum_y + arr[idx][1])
    dfs(idx+1, cnt, sum_x, sum_y)

tc = int(sys.stdin.readline())

for t in range(tc):

    n = int(sys.stdin.readline())
    
    arr = []
    visited = [0 for _ in range(n)]
    total_x = 0
    total_y = 0
    for _ in range(n):
        tmp = list(map(int, sys.stdin.readline().split()))
        total_x += tmp[0]
        total_y += tmp[1]
        arr.append(tmp)

    min_ret = 1e18
    
    dfs(0, 0, 0, 0)
    sys.stdout.write(str(min_ret)+"\n")
