'''
스코빌 지수가 가장 낮은 두 음식을 섞음
섞은 음식의 스코빌 지수 = 덜 매운 음식의 스코빌 지수 + (더 매운 음식의 스코빌 지수 * 2)
모든 음식의 스코빌 지수를 k 이상으로 만들기 위해 섞어야 하는 최소 횟수
모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우에는 -1 return
'''
import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    
    while (len(scoville) >= 2):
        if (scoville[0] >= K): # 모든 음식의 스코빌 지수가 K 이상
            break
            
        first = heapq.heappop(scoville)
        second = heapq.heappop(scoville)
        
        new = first + second * 2
        heapq.heappush(scoville, new)
        answer += 1
    
    if (scoville[0] < K):
        return -1;
        
    return answer