import sys 

T = int(sys.stdin.readline())

for _ in range(T):
    n = int(sys.stdin.readline())
    wears = {}
    results = 1
    for i in range(n):
        w, wt = sys.stdin.readline().strip().split()
        if wt in wears:
            wears[wt] += 1
        else:
            wears[wt] = 1
    for wear in wears:
        results *= (wears[wear]+1)
    sys.stdout.write(str(results-1)+"\n")