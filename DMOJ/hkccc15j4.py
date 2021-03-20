l = int(input())
n = int(input())
se = []
for i in range(n):
    se.append(list(map(int,input().split())))

se.sort()
# print(se)
ind = 0
mx = 0
for i in se:
    if i[0] > ind:
        mx = max(mx, min(l,i[0]) - ind)
    if i[1] > ind:
        ind = i[1]
mx = max(mx, l-se[-1][1])
print(mx)