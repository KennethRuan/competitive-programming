from sys import stdin

input = stdin.readline

m = int(input())

dp = [1] + [0]*(m-1)
rivers = [[]for i in range(m)]

while True:
    a,b = map(int,input().split())
    if a == 0 and b == 0:
        break
    rivers[a-1].append(b)
mills = []
for i in range(m):
    for j in rivers[i]:
        dp[j-1] += dp[i]

print(dp[-1])