n, b = map(int, input().split())

ans = ''

while n > 0:
    add = int(n % b)
    if add >= 10:
        add = chr(ord('A') + add - 10)
    
    ans += str(add)
    n //= b
    
print(ans[::-1])