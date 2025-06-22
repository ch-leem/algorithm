# 백준 2363 : 치즈 (https://www.acmicpc.net/problem/2636)
import sys 
sys.setrecursionlimit(10**6)
dy = [0,0,1,-1]
dx = [1,-1,0,0]

def go(y, x):
    visited[y][x] = 1
    if a[y][x] == 1:
        outside.append((y, x))
        return
    
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny >= n or ny < 0 or nx >= m or nx < 0 or visited[ny][nx]:
            continue
        go(ny, nx)
    return

n, m = map(int, sys.stdin.readline().split())
a = []
for i in range(n):
    a.append(list(map(int, sys.stdin.readline().split())))

h = 1
while True:
    visited = [[0] * m for _ in range(n)]
    outside = []
    go(0, 0)
    cnt = len(outside)
    for i, j in outside:
        a[i][j] = 0
    
    flag = True
    for i in range(n):
        for j in range(m):
            if a[i][j] == 1:
                flag = False
    if flag:
        break
    h += 1
sys.stdout.write(str(h)+"\n")
sys.stdout.write(str(cnt)+"\n")