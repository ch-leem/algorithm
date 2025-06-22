# 백준 1436 : 영화감독 숌 (https://www.acmicpc.net/problem/1436)
import sys
    
n = int(sys.stdin.readline())
i = 666
cnt = 0
while True:
    if '666' in str(i):
        cnt += 1
    if cnt == n:
        break
    i += 1
sys.stdout.write(str(i)+"\n")