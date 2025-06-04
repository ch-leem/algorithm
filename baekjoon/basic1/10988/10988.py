import sys

word = list(sys.stdin.readline().strip())

reverse_word = list(reversed(word))

if reverse_word == word:
    answer = 1
else:
    answer = 0

sys.stdout.write(str(answer))