n = int(input())
st = list(map(int,input().split()))
incl = 0
excl = 0
if n == 2:
    print(abs(st[1]-st[0]))
else:
    incl = abs(st[1]-st[0])
    for i in range(2,len(st)):
        p = incl
        incl = min(incl+abs(st[i]-st[i-1]),excl+abs(st[i]-st[i-2]))
        excl = p
    excl += abs(st[n-1]-st[n-2])
    print(min(excl,incl))