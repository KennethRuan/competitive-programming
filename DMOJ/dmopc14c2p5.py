from sys import stdin

input = stdin.readline

m,n = map(int,input().split())

dp = [1] + [0]*(m-1)
rivers = [[]for i in range(m)]

for i in range(n):
    a,b = map(int,input().split())
    rivers[a-1].append(b)
mills = []
for i in range(m):
    l = len(rivers[i])
    if l == 0:
        mills.append(i)
    else:
        calc = float(dp[i])/l
        for j in rivers[i]:
            dp[j-1] += calc

for i in mills:
    print(round(dp[i],9))