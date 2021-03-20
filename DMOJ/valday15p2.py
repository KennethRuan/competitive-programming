from sys import stdin
input = stdin.readline

c,m = map(int,input().split())
dp = [[0 for i in range(m+1)]for j in range(c+1)]
for i in range(1,c+1):
  v, w = map(int,input().split())
  for j in range(w,m+1):
    dp[i][j] = v
  for j in range(1,m+1):
    if j < w:
      dp[i][j] = dp[i-1][j]
    else:
      dp[i][j] = max(dp[i-1][j-w]+v,dp[i-1][j])

print(dp[c][m])