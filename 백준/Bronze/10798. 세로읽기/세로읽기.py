MAX = 15
str_list = []

for i in range(5):
    string = input()
    str_list.append(string + " " * (MAX - len(string)))

ans = ''
for i in range(MAX):
    for j in range(5):
        ans += str_list[j][i];

print(ans.replace(" ", ''))