s = input()

substrs = set()

for i in range(1, len(s) + 1):
    for j in range(len(s) - i + 1):
        substrs.add(s[j:j+i])
    
print(len(substrs))