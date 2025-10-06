MAX_TIME = 101

n, k = map(int, input().split())
products = list(map(int, input().split()))

multitab = set()
ans = 0

for i in range(k):
    if products[i] in multitab:
        continue
    
    if len(multitab) < n:
        multitab.add(products[i])
        continue
    
    next_time = {p: MAX_TIME for p in multitab}
    for j in range(i + 1, k):
        if products[j] not in multitab or next_time[products[j]] != MAX_TIME:
            continue
        
        next_time[products[j]] = j
    
    product_to_remove = sorted(next_time.items(), key=lambda k: k[1], reverse=True)[0][0]
    
    multitab.remove(product_to_remove)
    ans += 1
    multitab.add(products[i])

print(ans)
