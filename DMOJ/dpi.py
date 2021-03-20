from sys import stdin
input = stdin.readline

n = int(input())
coins = list(map(float,input().split()))
dp = [0 for i in range(n+1)]
dp[0] = 1-coins[0]
dp[1] = coins[0]
tot = 0
for i in range(1,n):
    # print(dp)
    for j in range(i+1,-1,-1):
        dp[j] = dp[j]*(1-coins[i]) + (dp[j-1]*coins[i] if j-1 >= 0 else 0)
        if i == n-1 and j > n/2:
            tot += dp[j]
if n == 1:
    print(dp[1])
else:
    print(tot)