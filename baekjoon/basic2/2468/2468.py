# 백준 2468 안전 영역 (https://www.acmicpc.net/problem/2468)
import sys
sys.setrecursionlimit(10**5)

dy = [0,0,1,-1]
dx = [1,-1,0,0]

def dfs(y, x):
    visited[y][x] = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i] 
        if ny >= n or ny < 0 or nx >= n or nx < 0:
            continue
        if visited[ny][nx] == 0 and mp[ny][nx] == 1:
            dfs(ny, nx)
    return

def dfs_stack(y, x):
    visited[y][x] = 1
    stack = []
    stack.append((y, x))

    while stack:
        cy, cx = stack.pop()
        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i] 
            if ny >= n or ny < 0 or nx >= n or nx < 0:
                continue
            if visited[ny][nx] == 0 and mp[ny][nx] == 1:
                stack.append((ny, nx))
                visited[ny][nx] = 1
    return

n = int(sys.stdin.readline())
a = []
h = 0
for i in range(n):
    s = list(map(int, sys.stdin.readline().split()))
    h = max(h, max(s))
    a.append(s)

mp = [[0] * n for _ in range(n)]

ret = 0
for rain in range(h):
    visited = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if a[i][j] <= rain:
                mp[i][j] = 0
            else:
                mp[i][j] = 1
    cnt = 0
    for i in range(n):
        for j in range(n):
            if visited[i][j] == 0 and mp[i][j] == 1:
                dfs_stack(i, j)
                cnt += 1
    ret = max(ret, cnt)
sys.stdout.write(str(ret)+"\n")


