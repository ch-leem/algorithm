# 백준 2583 : 영역 구하기 (https://www.acmicpc.net/problem/2583)
import sys
sys.setrecursionlimit(10**6)

dy = [0,0,1,-1]
dx = [1,-1,0,0]

def dfs(y, x):
    visited[y][x] = 1
    ret = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny >= m or ny < 0 or nx >= n or nx < 0: continue
        if visited[ny][nx] == 0 and a[ny][nx] != 1:
            ret += dfs(ny,nx)
    return ret

m, n, k = map(int, sys.stdin.readline().split())
a = [[0] * n for _ in range(m)]
visited = [[0] * n for _ in range(m)]

for _ in range(k):
    x1, y1, x2, y2 = map(int, sys.stdin.readline().split())
    for i in range(y1, y2):
        for j in range(x1, x2):
            a[i][j] = 1
ret = []
for i in range(m):
    for j in range(n):
        if visited[i][j] == 0 and a[i][j] != 1:
            ret.append(dfs(i, j))    

ret.sort()
sys.stdout.write(str(len(ret))+"\n")
for ans in ret:
    sys.stdout.write(str(ans)+" ")
sys.stdout.write("\n")
