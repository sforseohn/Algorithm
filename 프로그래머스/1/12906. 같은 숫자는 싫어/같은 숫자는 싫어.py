def solution(arr):
    stack = [arr[0]]
    
    for num in arr:
        if num != stack[-1]:
            stack.append(num)
    
    return stack