import sys

a, b, c = map(int, sys.stdin.readline().split())

def solution(a, b):
    if b == 1:
        return a % c
    ret = solution(a, b//2)
    ret = (ret * ret) % c
    if (b % 2):
        ret = (ret * a) % c
    return ret

ans = solution(a, b)
sys.stdout.write(str(ans)+"\n")