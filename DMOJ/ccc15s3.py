a = int(input())
g = [0 for i in range(a+1)]
b = int(input())
c = 0
for i in range(b):
    p = int(input())
    n = g[p]
    while p > 0 and n > 0:
        n = g[p]
        g[p] += 1
        p -= n
    if p <= 0:
        break
    else:
        g[p] = 1
        c += 1

print(c)