# 백준 1012 : 유기농 배추 (https://www.acmicpc.net/problem/1012)

import sys
sys.setrecursionlimit(10**5)

dy = [0,0,1,-1]
dx = [1,-1,0,0]

def dfs(y, x):
    visited[y][x] = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny >= n or ny < 0 or nx >= m or nx < 0:
            continue
        if visited[ny][nx] == 0 and a[ny][nx] == 1:
            dfs(ny, nx)
    return

def dfs_stack(y, x):
    visited[y][x] = 1
    stk = []
    stk.append((y,x))

    while stk:
        cy, cx = stk.pop()
        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            if ny >= n or ny < 0 or nx >= m or nx < 0:
                continue
            if visited[ny][nx] == 0 and a[ny][nx] == 1:
                visited[ny][nx] = 1
                stk.append((ny, nx))
        

T = int(sys.stdin.readline())
for _ in range(T):
    m, n, k = map(int, sys.stdin.readline().split())
    a = [[0] * m for _ in range(n)]
    visited = [[0] * m for _ in range(n)]
    for i in range(k):
        x, y = map(int, sys.stdin.readline().split())
        a[y][x] = 1

    cnt = 0
    for i in range(n):
        for j in range(m):
            if visited[i][j] == 0 and a[i][j] == 1:
                dfs(i, j)
                cnt += 1
    
    sys.stdout.write(str(cnt)+"\n")