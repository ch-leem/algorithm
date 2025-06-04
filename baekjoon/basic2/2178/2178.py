# 백준 2178 : 미로 탐색 (https://www.acmicpc.net/problem/2178)
import sys
from collections import deque

def bfs():
    visited[0][0] = 1
    q = deque()
    q.append((0, 0))

    while q:
        y, x = q.popleft()
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            if ny >= n or ny < 0 or nx >= m or nx < 0:
                continue
            if visited[ny][nx] == 0 and a[ny][nx] == 1:
                q.append((ny, nx))
                visited[ny][nx] = visited[y][x] + 1
    return

n, m = map(int, sys.stdin.readline().split())
a = []
for i in range(n):
    s = list(map(int, sys.stdin.readline().rstrip()))
    a.append(s)

dy = [0,0,1,-1]
dx = [1,-1,0,0]

visited = [[0] * m for _ in range(n)]
bfs()
sys.stdout.write(str(visited[n-1][m-1])+"\n")
