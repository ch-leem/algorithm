# 백준 9012 : 괄호 (https://www.acmicpc.net/problem/9012)
import sys
    
tc = int(sys.stdin.readline())
for _ in range(tc):
    stk = []
    s = sys.stdin.readline().rstrip()
    stk.append(s[0])
    for i in range(1, len(s)):
        if len(stk) and stk[-1] == '(' and s[i] == ')':
            stk.pop()
        else:
            stk.append(s[i])
    if len(stk):
        sys.stdout.write("NO\n")
    else:
        sys.stdout.write("YES\n")