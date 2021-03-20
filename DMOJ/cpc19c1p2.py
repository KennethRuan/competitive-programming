n,k = map(int,input().split())
items = map(int,input().split())
items = sorted(items)
p1 = 0
p2 = 0
c = 0
while p2<n:
    if abs(items[p2]-items[p1]) <= k:
        c = max(p2-p1+1,c)
        p2 += 1
    else:
        p1 += 1

print(c)