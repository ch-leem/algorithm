# 백준 14502 : 연구소 (https://www.acmicpc.net/problem/14502)
import sys
from itertools import combinations
sys.setrecursionlimit(10**6)
dy = [0,0,1,-1]
dx = [1,-1,0,0]

def wall(yx_list, w):
    for y, x in yx_list:
        visited[y][x] = w
    return
    
def spread(y, x):
    visited[y][x] = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny >= n or ny < 0 or nx >= m or nx < 0:
            continue
        if visited[ny][nx] == 0 and a[ny][nx] == 0:
            spread(ny, nx)
    return

def go(y, x):
    ret = 1
    visited[y][x] = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny >= n or ny < 0 or nx >= m or nx < 0:
            continue
        if visited[ny][nx] == 0 and a[ny][nx] == 0:
            ret += go(ny, nx)
    return ret

n, m = map(int, sys.stdin.readline().split())
a = []
for i in range(n):
    a.append(list(map(int, sys.stdin.readline().split())))

wall_list = []
for i in range(n):
    for j in range(m):
        if a[i][j] == 0:
            wall_list.append((i, j))

max_area = 0
combi = list(combinations(wall_list, 3))
for com in combi:
    visited = [[0] * m for _ in range(n)]
    area = 0
    wall(com, 1)
    for i in range(n):
        for j in range(m):
            if a[i][j] == 2:
                spread(i, j)
    
    for i in range(n):
        for j in range(m):
            if visited[i][j] == 0 and a[i][j] == 0:
                area += go(i, j)
    max_area = max(max_area, area)
    wall(com, 0)

sys.stdout.write(str(max_area)+"\n")
