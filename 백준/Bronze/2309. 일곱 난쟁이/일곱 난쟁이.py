DWARF_CNT = 9
TOTAL_HEIGHT = 100

def find_fakes(dwarfs):
    for i in range(DWARF_CNT - 1):
        for j in range(i + 1, DWARF_CNT):
            if dwarfs[i] + dwarfs[j] == diff:
                return [dwarfs[i], dwarfs[j]]

dwarfs = [0] * DWARF_CNT
for i in range(DWARF_CNT):
    dwarfs[i] = int(input())
    
height_sum = sum(dwarfs)
diff = height_sum - TOTAL_HEIGHT

dwarfs.sort()
fake_dwarf = find_fakes(dwarfs)

for dwarf in dwarfs:
    if dwarf not in fake_dwarf:
        print(dwarf)
