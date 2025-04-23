import sys

n = int(sys.stdin.readline())

cnt = 0
for i in range(n):
    s = sys.stdin.readline().strip()
    stack = []
    for c in s:
        if len(stack) and stack[-1] == c:
            stack.pop()
        else:
            stack.append(c)
    if len(stack) == 0:
        cnt += 1
sys.stdout.write(str(cnt)+"\n")