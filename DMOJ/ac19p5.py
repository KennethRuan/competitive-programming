import sys
sys.setrecursionlimit(300000)
input = sys.stdin.readline

n = int(input())
dp = [[-1 for i in range(n)]for i in range(n)]
gr = []
ml = 0
for i in range(n):
    gr.append(list(map(int,input().split())))


def dfs(i,j):
    if dp[i][j] > -1:
        return dp[i][j]
    dp[i][j] = 0
    dp[i][j] = max(dfs(i-1,j)+1 if i-1 >= 0 and gr[i-1][j] < gr[i][j] else 0,
                   dfs(i+1,j)+1 if i+1 < n and gr[i+1][j] < gr[i][j] else 0,
                   dfs(i,j-1)+1 if j-1 >= 0 and gr[i][j-1] < gr[i][j] else 0,
                   dfs(i,j+1)+1 if j+1 < n and gr[i][j+1] < gr[i][j] else 0)
    return dp[i][j]


for i in range(n):
    for j in range(n):
        ml = max(ml,dfs(i,j))

print(ml)