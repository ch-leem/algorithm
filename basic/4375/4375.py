import sys 

for line in sys.stdin:
    if line == '\n':
        break
    n = int(line)
    one = ""
    cnt = 0
    loop = True
    while loop:
        one += '1'
        cnt += 1
        if int(one) % n == 0:
            loop = False
    sys.stdout.write(str(cnt)+"\n")