from sys import stdin
input = stdin.readline

n = int(input())
ha = []
ea = []
pa = []

for i in range(n):
    inp = list(map(int,input().split()))
    ha.append(inp[0])
    ea.append(inp[1])
    pa.append(inp[2])
# print(ha,ea,pa)
s = int(input())
dp = [[0,99999999] for i in range(s+1)]
dp[0][1] = 0
for i in range(n):
    h,e,p = ha[i],ea[i],pa[i]
    while h > 0:
        for j in range(s,p-1,-1):
            if dp[j][0] == dp[j-p][0]+h:
                dp[j][1] = min(dp[j][1],dp[j - p][1] + 1)
            if dp[j][0] < dp[j-p][0]+h:
                dp[j][0] = dp[j-p][0]+h
                # print("current value", j, dp[j][0])
                # print(dp[j][1])
                # print("previous value", j - p, dp[j - p][0])
                # print(dp[j - p][1] + 1)
                dp[j][1] = dp[j-p][1]+1
        h -= e

ans = [0,99999999]
for i in range(s,-1,-1):
    if dp[i][0] >= ans[0]:
        ans[0] = dp[i][0]
        if dp[i][1] < ans[1]:
            ans[1] = dp[i][1]
print(ans[0])
print(ans[1])