def find(root):
    p = root
    while id1[root] != root:
        root = id1[root]

    while p != root:
        n = id1[p]
        id1[p] = root
        p = n

    return root


def find2(root):
    p = root
    while id2[root] != root:
        root = id2[root]

    while p != root:
        n = id2[p]
        id2[p] = root
        p = n

    return root

m = int(input()) #Number of pens
g1 = []
g2 = []
tempe = [set() for i in range(m+1)]
for i in range(1,m+1):
    a = list(map(int,input().split()))
    n = a[1:a[0]+1] #Nodes
    n.append(a[1])
    w = a[a[0]+1:] #Weights of edges
    x = a[0]
    for j in range(x):
        e = (w[j],min(n[j],n[j+1]),max(n[j],n[j+1]))
        found = False
        for k in range(1,i):
            if e in tempe[k]:
                found = True
                g1.append((e[0],k,i))
                g2.append((e[0],k,i))
                tempe[k].remove(e)
                break
        if not found:
            tempe[i].add(e)

for node,i in enumerate(tempe):
    for w,a,b in i:
        g2.append((w,0,node))

g1 = sorted(g1,key=lambda x:x[0])
g2 = sorted(g2,key=lambda x:x[0])

nc1 = m
tw1 = 0
id1 = [i for i in range(m+1)]
sz1 = [1 for i in range(m+1)]
for i in g1:
    p1 = find(i[1])
    p2 = find(i[2])
    if p1 != p2:
        if sz1[p1] >= sz1[p2]:
            id1[p2] = p1
            sz1[p1] += sz1[p2]
        else:
            id1[p1] = p2
            sz1[p2] += sz1[p1]
        tw1 += i[0]
        nc1 -= 1

if nc1 > 1:
    tw1 = float("inf")

nc2 = m + 1
tw2 = 0
id2 = [i for i in range(m+1)]
sz2 = [1 for i in range(m+1)]
for i in g2:
    p1 = find2(i[1])
    p2 = find2(i[2])
    if p1 != p2:
        if sz2[p1] >= sz2[p2]:
            id2[p2] = p1
            sz2[p1] += sz2[p2]
        elif sz2[p2] > sz2[p1]:
            id2[p1] = p2
            sz2[p2] += sz2[p1]
        tw2 += i[0]
        nc2 -= 1

if nc2 > 1:
    tw2 = float("inf")

print(min(tw1,tw2))