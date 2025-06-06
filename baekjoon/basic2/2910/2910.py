# 백준 2910 : 빈도 정렬 (https://www.acmicpc.net/problem/2910)

import sys

n, c = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))

d = {}
for num in a:
    if num in d:
        d[num] += 1
    else:
        d[num] = 1

sorted_dict = dict(sorted(d.items(), key=lambda item : item[1], reverse=True))
ret = []
for key in sorted_dict:
    ret.extend([str(key)] * d[key])
sys.stdout.write(' '.join(ret)+'\n')