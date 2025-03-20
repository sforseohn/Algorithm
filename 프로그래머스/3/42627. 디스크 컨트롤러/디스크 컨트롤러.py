'''
작업의 번호, 작업의 요청 시각, 작업의 소요 시간을 저장해 두는 대기 큐
하드디스크가 작업을 하고 있지 않고 대기 큐가 비어있지 않다면 가장 우선순위가 높은 작업을 대기 큐에서 꺼내서 하드디스크에 그 작업
작업의 소요시간이 짧은 것, 작업의 요청 시각이 빠른 것, 작업의 번호가 작은 것 순으로 우선순위가 높습니다.
'''

import heapq

def solution(jobs): 
    jobs_length = len(jobs)
    time = 0
    q = []
    waiting_sum = 0
    # 요청 시점, 소요 시간 -> 소요 시간, 요청 시점, 작업 번호로 바꾸기
    jobs = [(jobs[i][0], jobs[i][1], i) for i in range(jobs_length)]
    heapq.heapify(jobs)
    
    while (len(jobs) != 0 or len(q) != 0):
        # 요청이 들어온 작업들을 대기 큐에 저장
        while (len(jobs) != 0 and jobs[0][0] <= time):
            to_add = heapq.heappop(jobs)
            heapq.heappush(q, (to_add[1], to_add[0], to_add[2]))
        
        # 하드디스크가 작업을 하고 있지 않고 대기 큐가 비어 있지 않다면
        if (len(q) != 0):
            # 가장 우선순위가 높은 작업 실행
            cur_job = heapq.heappop(q)
            time += cur_job[0]
            waiting_sum += time - cur_job[1]
        else:
            time += 1
    
    return waiting_sum // jobs_length