croatia_patterns = [
"c=",
"c-",
"dz=",
"d-",
"lj",
"nj",
"s=",
"z="
]

text = input()

ans = 0

for pattern in croatia_patterns:
    cnt = text.count(pattern)
    
    if (cnt != -1):
        ans += cnt

ans += len(text) - ans * 2

print(ans)