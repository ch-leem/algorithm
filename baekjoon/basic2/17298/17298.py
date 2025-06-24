# 백준 17298 : 오큰수 (https://www.acmicpc.net/problem/17298)
import sys

n = int(sys.stdin.readline())

a = list(map(int, sys.stdin.readline().split()))

stk = [0]
ret = [-1] * 1000004
for i, v in enumerate(a):
    if i == 0:
        continue
    while stk and a[stk[-1]] < a[i]:
        ret[stk[-1]] = a[i]
        stk.pop()
    stk.append(i)

for i in range(n):
    sys.stdout.write(str(ret[i])+" ")
sys.stdout.write("\n")