# 백준 16234 : 인구 이동 (https://www.acmicpc.net/problem/16234)
import sys
sys.setrecursionlimit(10**6)

dy = [0,0,1,-1]
dx = [1,-1,0,0]

def go(y, x):
    global is_move
    
    for d in range(4):
        ny = y + dy[d]
        nx = x + dx[d]
        if ny >= n or ny < 0 or nx >= n or nx < 0:
            continue
        if abs(a[y][x]-a[ny][nx]) >= l and abs(a[y][x]-a[ny][nx]) <= r:
            line[y][x].append((ny, nx))
            is_move = True
    return

def dfs(y, x, group):
    visited[y][x] = group
    person_cnt = a[y][x]
    kan_cnt = 1

    for v in line[y][x]:
        ny = v[0]
        nx = v[1]
        if visited[ny][nx] == group:
            continue

        ret1, ret2 = dfs(ny, nx, group)
        person_cnt += ret1
        kan_cnt += ret2
    return person_cnt, kan_cnt
        
n, l, r = map(int, sys.stdin.readline().split())

a = []
for i in range(n):
    a.append(list(map(int, sys.stdin.readline().split())))

day = 0
while True:

    is_move = False

    # 국경선 초기화, 연합 초기화
    line = [[[] for _ in range(n)] for _ in range(n)]
    visited = [[0] * n for _ in range(n)]

    # 국경선 open
    for i in range(n):
        for j in range(n):
            go(i, j)
    
    # 연합
    group = 1
    group_person = [-1]

    for i in range(n):
        for j in range(n):
            if visited[i][j] != 0:
                continue
            person_cnt, kan_cnt = dfs(i, j, group)
            person = person_cnt // kan_cnt
            group_person.append(person)
            group += 1
    
    for i in range(n):
        for j in range(n):
            if visited[i][j] == 0:
                continue
            a[i][j] = group_person[visited[i][j]]
    
    if is_move == False:
        break

    day += 1

sys.stdout.write(str(day)+"\n")