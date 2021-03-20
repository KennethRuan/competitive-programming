h, w = map(int,input().split())

dp = [[0 for _ in range(w)] for _ in range(h)]
dp[0][0] = 1
for i in range(h):
    row = input()
    for j in range(w):
        if row[j] != "#":
            dp[i][j] += (dp[i-1][j] if i-1 >= 0 else 0) + (dp[i][j-1] if j-1 >= 0 else 0)
            dp[i][j] %= (1e9 + 7)
print(int(dp[h-1][w-1] % (1e9 + 7)))