# 백준 2852 : NBA 농구 (https://www.acmicpc.net/problem/2852)
import sys

def change_s(tmp):
    m, s = tmp.split(':')
    return int(m) * 60 + int(s)

def to_format(ret):
    m = ret // 60
    s = ret % 60
    result = f"{m:02}:{s:02}"
    return result

n = int(sys.stdin.readline())
cnt = 0
last = ''
ret_a, ret_b, draw = 0, 0, 0
end_time = 48 * 60
for _ in range(n):
    tn, tmp = sys.stdin.readline().rstrip().split()

    if tn == '1': cnt += 1
    else: cnt -= 1

    s = change_s(tmp)

    if cnt > 0:
        if last != 'a':
            ret_a += end_time - s
        last = 'a'
    elif cnt == 0:
        draw = end_time - s
        if last == 'a':
            ret_a -= draw
        elif last == 'b':
            ret_b -= draw
        last = 'd'
    else:
        if last != 'b':
            ret_b += end_time - s
        last = 'b'

ret1 = to_format(ret_a)
ret2 = to_format(ret_b)

sys.stdout.write(ret1+'\n')
sys.stdout.write(ret2+'\n')

'''
import sys

def change_s(s):
    m, sec = s.split(':')
    return int(m) * 60 + int(sec)

def go(sum, s):
    return sum + (change_s(s) - change_s(prev))

def print_ans(sum):
    m = sum // 60
    sec = sum % 60
    print(f"{m:02}:{sec:02}")
    return

n = int(sys.stdin.readline())
a = 0
b = 0
a_sum = 0
b_sum = 0
for _ in range(n):
    t, s = sys.stdin.readline().rstrip().split()
    if a > b:
        a_sum = go(a_sum, s)
    elif b > a:
        b_sum = go(b_sum, s)
    if t == '1':
        a += 1
    else:
        b += 1
    prev = s
if a > b : a_sum = go(a_sum, "48:00")
elif b > a : b_sum = go(b_sum, "48:00")
print_ans(a_sum)
print_ans(b_sum)
'''