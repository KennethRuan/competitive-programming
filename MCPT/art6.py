n = int(input())
l,r,bx,by = map(int,input().split())
se = []
p1 = 0
p2 = 0

def xint(x1, y1, x2, y2):
    return x1 - (x2 - x1) / (y2 - y1) * y1

for i in range(n):
    x1,y1,x2,y2 = map(int,input().split())
    p1 = xint(x1,y1,bx,by)
    p2 = xint(x2,y2,bx,by)
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
print("{0:0.3f}".format(tot))

# 1
# 261 999999204 363554941 484442800
# 291882530 14378424 291884587 1