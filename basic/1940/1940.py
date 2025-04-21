import sys

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

nums = list(map(int, sys.stdin.readline().split()))

cnt = 0
for num in nums:
    if (m-num) in nums:
        cnt += 1

cnt = cnt // 2    
sys.stdout.write(str(cnt)+"\n")