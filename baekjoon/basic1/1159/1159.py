import sys

n = int(sys.stdin.readline())

dict = {}
for i in 'abcdefghijklmnopqrstuvwxyz':
    dict[i] = 0

for i in range(n):
    name = sys.stdin.readline().strip()
    first_name = name[0]
    dict[first_name] += 1

cnt = []
for i in 'abcdefghijklmnopqrstuvwxyz':
    if dict[i] >= 5:
        cnt.append(i)

if len(cnt) == 0:
    sys.stdout.write("PREDAJA")
else:
    sys.stdout.write(''.join(cnt))