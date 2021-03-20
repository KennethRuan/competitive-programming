s = list(map(int,input().split()))[1]
coins = list(map(int,input().split()))
dp = [1001 for i in range(s+1)]
dp[0] = 0
for i in range(s):
  for j in coins:
    if i+j <= s:
      if dp[i+j] > dp[i]+1:
        dp[i+j] = dp[i] + 1

print("NO" if dp[s] == 1001 else "YES")