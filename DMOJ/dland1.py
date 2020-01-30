n,q = map(int,input().split())
grades = map(int,input().split())
da = [0 for i in range(n)]
for i in range(q):
    l,r = map(int,input().split())
    da[l-1] += 1
    if r < n:
        da[r] -= 1
t = []
s = 0
for i in range(n):
    s += da[i]
    t.append(s)

t = sorted(t,reverse = True)
grades = sorted(grades)
s = 0
for i in range(n):
    s += t[i]*grades[i]
print(s)