n,m = map(int,input().split())
ie = [i for i in range(n+1)]
sz = [1 for i in range(n+1)]

def find(root):
    p = root
    while root != ie[root]:
        root = ie[root]
    while p != root:
        n = ie[p]
        ie[p] = root
        p = n
    return root

def union(a,b):
    if sz[a] >= sz[b]:
        sz[a] += sz[b]
        ie[b] = a
    else:
        sz[b] += sz[a]
        ie[a] = b
q = []
for i in range(m):
    q.append(list(map(int,input().split())))
q = sorted(q, key = lambda x:x[2])
s = 0
for i in range(m):
    u,v,w = q[i]
    a = find(u)
    b = find(v)
    if a != b:
        union(a,b)
        n -= 1
        s += w

print(s if n == 1 else 0)