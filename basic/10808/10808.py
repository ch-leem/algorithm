import sys

dic = {}
for c in 'abcdefghijklmnopqrstuvwxyz':
    dic[c] = 0

# 문자 리스트로 받고
aa = sys.stdin.readline().strip()

for a in aa:
    dic[a] += 1

for c in dic:
    sys.stdout.write(str(dic[c]))
    sys.stdout.write(' ')
