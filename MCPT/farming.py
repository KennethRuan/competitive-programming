from sys import stdin

input = stdin.readline
n, k = map(int, input().split())
a = list(map(int,input().split()))

dp = [[[0 for _ in range(2)] for __ in range(2)] for ___ in range(n)]

dp[0][1][1] = a[0]
for i in range(1,n):
    if i >= k:
        dp[i][0][1] = max(dp[i-k][1][1], dp[i-1][0][1])
        dp[i][0][0] = max(dp[i-k][1][0], dp[i-1][0][0])
    else:
        dp[i][0][1] = dp[i-1][0][1]
        dp[i][0][0] = dp[i-1][0][0]
    dp[i][1][1] = max(dp[i-1][0][1] + a[i], dp[i-1][1][1])
    dp[i][1][0] = max(dp[i-1][0][0] + a[i], dp[i-1][1][1] + a[i], dp[i-1][1][0])
ans = max(dp[n-1][0][0], max(dp[n-1][0][1], max(dp[n-1][1][0], dp[n-1][1][1])))

print(ans)