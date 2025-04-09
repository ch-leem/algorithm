import sys

n, k = map(int, sys.stdin.readline().split())
t = list(map(int, sys.stdin.readline().split()))

current = sum(t[:k])
max_sum = current

for i in range(k, n):
    current = current - t[i-k] + t[i]
    max_sum = max(max_sum, current)

sys.stdout.write(str(max_sum)+"\n")