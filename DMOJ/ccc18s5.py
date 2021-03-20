from sys import stdin

input = stdin.readline

def findr(root):
    d = root
    while idr[root] != root:
        root = idr[root]

    while d != root:
        f = idr[d]
        idr[d] = root
        d = f

    return root


def findc(root):
    d = root
    while idc[root] != root:
        root = idc[root]

    while d != root:
        f = idc[d]
        idc[d] = root
        d = f

    return root


# column values should be multiplied by the amt of rows vice versa
# n is number of rows
# m is number of columns
n, m, p, q = map(int,input().split()) # planets, cities, flights, portals
edges = []
tot = 0
for i in range(p):
    a, b, c = map(int,input().split())
    a, b = a-1, b-1
    edges.append([c, a, b, 0])  # 0 is intercity, between columns
    tot += c*n
for i in range(q):
    x, y, z = map(int,input().split())
    x, y = x-1, y-1
    edges.append([z, x, y, 1])  # 1 is interplanetary, between rows
    tot += z*m

# Weight, Dest1, Dest2

edges.sort()
# print(edges)

idr = [i for i in range(m)]
idc = [i for i in range(n)]
cost = 0
for w,a,b,i in edges:
    if m > 1 or n > 1:
        if i == 0:
            ii = findr(a)
            jj = findr(b)
            if ii != jj:
                idr[jj] = idr[ii]
                m -= 1
                cost += w * n
        else:
            ii = findc(a)
            jj = findc(b)
            if ii != jj:
                idc[jj] = idc[ii]
                n -= 1
                cost += w * m

print(tot-cost)