from sys import stdin
input = stdin.readline

ans = 0

n,m,k = map(int, input().split())
arr = []
if n-1 > 0:
    arr = list(map(int, input().split()))
val = list(map(int, input().split())) + [0]

i = 0
j = 0
sum = val[j]
ans = max(ans, sum)

while j < n:
    while j < n-1 and arr[j] <= m:
        j += 1
        sum += val[j]
        if (j - i + 1) > k:
            sum -= val[i]
            i += 1
        ans = max(sum, ans)
    while i <= j:
        sum -= val[i]
        i += 1
    j += 1
    sum += val[j]
    ans = max(sum, ans)

print(ans)