def solution(schedules, timelogs, startday):

    n = len(timelogs)
    for i in range(n):
        tmp_h = schedules[i] // 100
        tmp_m = (schedules[i] % 100) + 10
        if tmp_m >= 60:
            schedules[i] = (tmp_h+1)*100 + (tmp_m-60)
        else:
            schedules[i] = tmp_h * 100 + tmp_m
        
    count = n
    
    for i in range(n):
        for j, timelog in enumerate(timelogs[i]):
            if (j + startday) % 7 == 6 or (j + startday) % 7 == 0:
                continue
            if timelog > schedules[i]:
                count -= 1
                break

    answer = count
    return answer

schedules = [730, 855, 700, 720]
timelogs = [[710, 700, 650, 735, 700, 931, 912], [908, 901, 805, 815, 800, 831, 835], [705, 701, 702, 705, 710, 710, 711], [707, 731, 859, 913, 934, 931, 905]]
startday = 1

result = solution(schedules, timelogs, startday)
print(result)

