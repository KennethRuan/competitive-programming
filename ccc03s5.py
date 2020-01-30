from sys import stdin
input = stdin.readline

c,r,d = map(int,input().split())
sz = [1 for i in range(c+1)]
id = [i for i in range(c+1)]
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

big = [-1 for i in range(c+1)]
roads = []
for i in range(r):
    roads.append(list(map(int,input().split())))

roads = sorted(roads,key = lambda x: x[2], reverse = True)

for i in roads:
    a = i[0]
    b = i[1]
    c = i[2]
    r1 = find(a)
    r2 = find(b)
    if (r1 != r2):
        if (sz[r1] < sz[r2]):
            sz[r2] += sz[r1]
            id[r1] = r2
        else:
            sz[r1] += sz[r2]
            id[r2] = r1

        if c > big[a]:
            big[a] = c
        if c > big[b]:
            big[b] = c

x = 100001
for i in range(d):
    x = min(big[int(input())], x)
print(x)
