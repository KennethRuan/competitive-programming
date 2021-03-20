n = int(input())
arr = list(map(int,input().split()))
inc = 0
exc = 0
for i in arr:
    p = inc
    inc = exc + i
    exc = max(exc,p)
print(max(inc,exc))