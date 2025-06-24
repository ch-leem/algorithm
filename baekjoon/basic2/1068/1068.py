# 백준 1068 : 트리 (https://www.acmicpc.net/problem/1068)
import sys 
sys.setrecursionlimit(10**6)

def dfs(u):
    visited[u] = 1
    ret = 0
    child = 0
    for v in adj[u]:
        if v == target or visited[v]:
            continue
        child += 1
        ret += dfs(v)
    if child == 0:
        ret += 1
    return ret

n = int(sys.stdin.readline())

adj = [[] for _ in range(n)]
visited = [0 for _ in range(n)]

node = list(map(int, sys.stdin.readline().split()))

for i in range(n):
    if node[i] == -1:
        root = i
    else:
        adj[node[i]].append(i)

target = int(sys.stdin.readline())

if target == root:
    sys.stdout.write("0\n")
else:
    ret = dfs(root)
    sys.stdout.write(str(ret)+"\n")