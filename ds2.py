from sys import stdin
input = stdin.readline

n,m = map(int,input().split())
sz = [1 for i in range(n+1)]
id = [i for i in range(n+1)]
nc = n
def find(p):
    root = p

    # Finds the root, id stores what the parent of that node is, when root = id[root] that's the root of the set
    while (root != id[root]):
        root = id[root]

    # Path compression to simplify amount of parents to loop through
    while (p != root):
        n = id[p]
        id[p] = root
        p = n

    return root


# def union(p,q):
#     r1 = find(p)
#     r2 = find(q)
#     if (r1 == r2):
#         return;
#     if (sz[r1] < sz[r2]):
#         sz[r2] += sz[r1]
#         id[r1] = r2
#     else:
#         sz[r1] += sz[r2]
#         id[r2] = r1
#     nc -= 1
edges = []
for i in range(m):
    a,b = map(int,input().split())
    r1 = find(a)
    r2 = find(b)
    if (r1 != r2):
        if (sz[r1] < sz[r2]):
            sz[r2] += sz[r1]
            id[r1] = r2
        else:
            sz[r1] += sz[r2]
            id[r2] = r1
        edges.append(i+1)
        nc -= 1

if (nc > 1):
    print("Disconnected Graph")
else:
    for i in range(len(edges)):
        print(edges[i])