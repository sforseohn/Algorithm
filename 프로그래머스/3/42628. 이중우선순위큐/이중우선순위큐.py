import heapq

def balance(heap):
    temp = []
    while (len(heap) > 0):
        temp.append(heapq.heappop(heap))
        
    for num in temp[:-1]:
        heapq.heappush(heap, num)
    
    return heap
    

def solution(operations):
    answer = []
    max_heap = []
    min_heap = []
    
    for operation in operations:     
        op = operation.split()[0]
        data = int(operation.split()[1])

        if (op == "I"): # 삽입
            heapq.heappush(max_heap, -data)
            heapq.heappush(min_heap, data)
            continue
        
        # 삭제
        if (len(max_heap) == 0):
            continue
        
        if (data == 1): # 최댓값 삭제
            heapq.heappop(max_heap)
        else:
            heapq.heappop(min_heap)
        
        while len(max_heap) > len(min_heap):
            max_heap = balance(max_heap)
        
        while len(min_heap) > len(max_heap):
            min_heap = balance(min_heap)
            
    if (len(max_heap) == 0):
        return [0, 0]
    
    return [-max_heap[0], min_heap[0]]