from sys import stdin
input = stdin.readline

for i in range(5):
  m = int(input())
  n = int(input())
  dp = [0 for i in range(m+1)]
  for i in range(n):
    a,b,c = input().split()
    v = int(b)
    w = int(c)
    for j in range(m,w-1,-1):
      dp[j] = max(dp[j],dp[j-w]+v)

  print(dp[m])