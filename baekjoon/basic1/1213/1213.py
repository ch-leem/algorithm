import sys
from collections import deque

cnt = [0 for _ in range(26)]
flag = 0
mid = ''
ans = deque([])

s = sys.stdin.readline().strip()
for c in s:
    cnt[ord(c) - ord('A')] += 1

for i in range(len(cnt)-1, -1, -1):
    if cnt[i] % 2 == 1:
        flag += 1
        mid = chr(i+ord('A'))
        if flag == 2:
            break
            
    for j in range(cnt[i]//2):
        ans.append(chr(i+ord('A')))
        ans.appendleft(chr(i+ord('A')))

if flag == 2:
    sys.stdout.write("I'm Sorry Hansoo"+"\n")
else:
    ans_list = list(ans)
    if len(mid):
        ans_list.insert(len(ans_list)//2, mid)
    sys.stdout.write(''.join(ans_list)+"\n")

