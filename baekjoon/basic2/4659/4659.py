# 백준 4659 : 비밀번호 발음하기 (https://www.acmicpc.net/problem/4659)
import sys

while True:
    condi = False
    cnt_m = 0
    cnt_j = 0
    s = sys.stdin.readline().rstrip()
    if s == "end": break
    for i in range(0, len(s)):
        if s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u':
            cnt_m += 1
            cnt_j = 0
            condi = True
        else:
            cnt_j += 1
            cnt_m = 0

        if cnt_m == 3 or cnt_j == 3:
            condi = False
            break
            
        if i != 0:
            if s[i] == 'e' or s[i] == 'o': continue
            if s[i] == s[i-1]:
                condi = False
                break
    if condi:
        sys.stdout.write('<'+s+'> '+"is acceptable.\n")
    else:
        sys.stdout.write('<'+s+'> '+"is not acceptable.\n")