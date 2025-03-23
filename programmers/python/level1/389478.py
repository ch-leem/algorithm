import sys 
import math

def solution(n, w, num):
    # 2차원 배열에 상자 쌓기
    # num에 해당하는 인덱스 찾기
    # num이 있는 인덱스 이후부터 행열 상자 카운트 
    box = 1
    count = 0
    target_idx = None

    h = int(math.ceil(n/w))
    arr = [[None] * h for _ in range(w)]

    for j in range(h):
        for i in range(w):
            if j % 2 == 0:
                x = i
                y = j
            else:
                x = w-i-1
                y = j

            arr[x][y] = box
            idx = (x,y)
            
            if box == num:
                target_idx = idx
            
            if target_idx is not None:
                if x == target_idx[0]:
                    count += 1

            if box == n:
                break
            box += 1
    
    answer = count
    return answer

n, w, num = map(int, sys.stdin.readline().rstrip().split())
count = solution(n, w, num)
print(count)