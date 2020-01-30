n = int(input())
patterns = {}
for i in range(n):
    c = 65
    s = input()
    maps = {}
    p = ""
    for j in s:
        if j not in maps.keys():
            maps[j] = chr(c)
            c += 1
        p += maps[j]
    if p in patterns.keys():
        patterns[p] += 1
    else:
        patterns[p] = 1
m = 0
for i in patterns:
    val = patterns[i]
    m += val*(val-1)/2
print(int(m))