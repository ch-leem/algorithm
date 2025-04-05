import sys

cnt = [0 for _ in range(26)]

# 문자 리스트로 받고
aa = sys.stdin.readline().strip()

for a in aa:
    idx = ord(a) - ord('a')
    cnt[idx] += 1

for c in cnt:
    sys.stdout.write(str(c))
    sys.stdout.write(' ')