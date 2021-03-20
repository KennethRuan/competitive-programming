from sys import stdin
input = stdin.readline

n,m = map(int,input().split())
wa= [0 for i in range(n)]
va= [0 for i in range(n)]
maxv = 0

for i in range(n):
  wa[i],va[i] = map(int,input().split())
  maxv += va[i]

dp = [1e11 for i in range(maxv+1)]
dp[0] = 0

a = 0

for i in range(n):
  w,v = wa[i],va[i]
  #print(dp)
  for j in range(maxv,v-1,-1):
    dp[j] = min(dp[j],dp[j-v]+w)

for i in range(maxv,-1,-1):
  # print(dp[i])
  if dp[i] <= m:
    print(i)
    break