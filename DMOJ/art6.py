n = int(input())
l,r,bx,by = map(int,input().split())
se = []
p1 = 0
p2 = 0
for i in range(n):
    x1,y1,x2,y2 = map(int,input().split())
    a = y1-by
    b = x1-bx
    if b == 0:
        p1 = bx
    else:
        m = a/b
        c = y1 - m * x1
        p1 = -c/m

    a = y2 - by
    b = x2 - bx
    if b == 0:
        p2 = bx
    else:
        m = a / b
        c = y2 - m * x2
        p2 = -c/ m

    se.append([max(l,min(p1,p2,r)),min(r,max(p1,p2,l))])

se.sort()
se.append([r,r])
# print(se)
ind = l
tot = 0
for i in se:
    if i[0] > ind:
        tot += i[0] - ind
    if i[1] > ind:
        ind = i[1]
print(tot)

# 1
# 261 999999204 363554941 484442800
# 291882530 14378424 291884587 1