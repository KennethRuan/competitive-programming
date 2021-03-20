n, m = map(int,input().split())
g = [set() for i in range(n+1)]
for i in range(m):
    a, b = map(int,input().split())
    g[a].add(b)
    g[b].add(a)
cnt = 0
for i in range(1, n+1):
    for j in g[i]:
        cnt += len(g[i].intersection(g[j]))
print(cnt//6)