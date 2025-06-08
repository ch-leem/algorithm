# 백준 2870 : 수학숙제 (https://www.acmicpc.net/problem/2870)
import sys

t = int(sys.stdin.readline())
ret = []
for _ in range(t):
    s = sys.stdin.readline().rstrip()
    tmps = ""
    for i in range(len(s)):
        if s[i] in '0123456789':
            tmps += s[i]
        else:
            if tmps != "":
                ret.append(int(tmps))
                tmps = ""
            else:
                continue
    if tmps != "":
        ret.append(int(tmps))

ret.sort()
for ans in ret:
    sys.stdout.write(str(ans)+'\n')