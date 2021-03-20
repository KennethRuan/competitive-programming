import sys

input = sys.stdin.readline
lmi = lambda: list(map(int, input().split()))
n = int(input())

if n == 1:
    print(0)
    sys.exit(0)

val = [0]+lmi()
mn = val[:]
mx = val[:]
id = [i for i in range(n+1)]
sz = [1 for i in range(n+1)]
rng = 0

def find(root):
    p = root
    while id[root] != root:
        root = id[root]
    while p != root:
        n = id[p]
        id[p] = root
        p = n
    return root

def union(a,b):
    global rng
    a = find(a)
    b = find(b)

    sz[a] += sz[b]
    id[b] = a
    mx[a] = max(mx[a], mx[b])
    mn[a] = min(mn[a], mn[b])
    rng = max(rng, mx[a] - mn[a])

edges = []
for i in range(n-1):
    edges.append(lmi())

order = lmi()

ans = [0 for i in range(n)]
for i,x in enumerate(order[::-1]):
    union(edges[x-1][0],edges[x-1][1])
    ans[n-i-2] = rng

for i in ans:
    print i,