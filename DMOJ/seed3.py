sz = int(input())
arr = [0 for i in range(sz+1)]
n = int(input())
for i in range(int(input())):
    a, b, v= map(int, input().split())
    arr[a-1] += v
    arr[b] -= v
for i in range(1, sz+1):
    arr[i] += arr[i-1]
cnt = 0
for i in range(sz):
    if arr[i] < n:
        cnt += 1
print(cnt)