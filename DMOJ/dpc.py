n = int(input())
ac = []
for i in range(n):
    ac.append(list(map(int,input().split())))
dp = [[0 for _ in range(3)]for _ in range(n)]
dp[0][0] = ac[0][0]
dp[0][1] = ac[0][1]
dp[0][2] = ac[0][2]

for i in range(1,n):
    for j in range(3):
        for k in range(3):
            if j == k:
                continue
            dp[i][j] = max(dp[i][j],dp[i-1][k]+ac[i][j])

ans = 0

for i in range(3):
    ans = max(ans,dp[n-1][i])

print(ans)