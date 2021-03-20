import operator
from sys import stdin
input = stdin.readline

n,v = map(int,input().split())
coins = list(map(int, input().split()))
qu = []
for i in range(v):
    qu.append(list(map(int,input().split())))
    qu[i].append(i)

arr = sorted(qu,key=operator.itemgetter(1,0))
dp = [0] + [10001 for i in range(10000)]
ans = [-1 for i in range(v)]
counter = 0
for i in range(arr[-1][1]):
    j=0
    while j < 10001:
        if j+coins[i] < 10001:
            if dp[j+coins[i]] > dp[j] + 1:
                dp[j+coins[i]] = dp[j] + 1
        if counter < v:
            if arr[counter][1] == i+1:
                if arr[counter][0] == j:
                    ans[arr[counter][2]] = dp[j]
                    if counter < v-1:
                        if arr[counter][1] == arr[counter+1][1] and arr[counter][0] == arr[counter+1][0]:
                            j -= 1
                    counter += 1
        j+=1

for i in range(v):
    print(-1 if ans[i] == 10001 else ans[i])