import sys

a, b, c =  map(int, sys.stdin.readline().split())

arr = [0 for _ in range(100)]

for i in range(3):
    start, end = map(int, sys.stdin.readline().split())
    for j in range(start, end):
        arr[j] += 1

fee = 0
for cnt in arr:
    if cnt == 0:
        continue
    elif cnt == 1: 
        fee += a
    elif cnt == 2:
        fee += 2*b
    else:
        fee += 3*c

sys.stdout.write(str(fee))