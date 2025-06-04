import sys
from itertools import combinations

ke = [int(sys.stdin.readline()) for _ in range(9)]

for i in combinations(ke, 7):
    if sum(i) == 100:
        sevens = sorted(list(i))
        break

for j in sevens:
    sys.stdout.write(str(j)+"\n")