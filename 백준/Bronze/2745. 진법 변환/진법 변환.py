n, b = input().split()
b = int(b)

ans = 0

for i in range(len(n)):
    x = n[len(n) - 1 - i]
    
    if not x.isdigit():
        x = ord(x) - ord('A') + 10
        
    ans += int(x) * pow(b, i)

print(ans)