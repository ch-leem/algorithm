import sys

n = int(sys.stdin.readline())
p_first, p_end = sys.stdin.readline().strip().split('*')

answers = []
for _ in range(n):
    s = sys.stdin.readline().strip()
    answer = 'NE'
    if len(s) >= len(p_first) + len(p_end):
        if s[:len(p_first)] == p_first:
            if s[len(s)-len(p_end):] == p_end:
                answer = 'DA'
    answers.append(answer)

for ans in answers:
    sys.stdout.write(ans+"\n")