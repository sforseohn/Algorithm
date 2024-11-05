def solution(s):    
    stack = []
    
    for c in s:
        if c == '(':
            stack.append(c)
        else:
            if len(stack):
                stack.pop()
            else:
                return False
    
    if len(stack):
        return False
    
    return True