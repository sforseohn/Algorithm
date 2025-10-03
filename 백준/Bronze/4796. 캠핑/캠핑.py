i = 1
while True:
    l, p, v = map(int, input().split())
    
    if l == 0:
        break
    
    cycle_count = v // p
    ans = cycle_count * l + min(l, v - p * cycle_count)
    
    print(f"Case {i}: {ans}")
    i += 1