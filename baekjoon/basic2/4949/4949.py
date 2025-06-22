# 백준 4949 : 균형잡힌 세상 (https://www.acmicpc.net/problem/4949)
import sys

def check(s):
    stk = []
    for c in s:
        if c == '(' or c == '[':
            stk.append(c)
        elif c == ')':
            if len(stk) == 0:
                return False
            if stk[-1] != '(':
                return False
            else:
                stk.pop()
        elif c == ']':
            if len(stk) == 0:
                return False
            if stk[-1] != '[':
                return False
            else:
                stk.pop()
    return len(stk) == 0
    
while True:
    s = sys.stdin.readline().rstrip()
    if s == ".":
        break
    if check(s):
        sys.stdout.write("yes\n")
    else:
        sys.stdout.write("no\n")