n, k = map(int,input().split())
a = list(map(int, input().split()))
a.sort()
psa = [0 for i in range(n+1)]
for i in range(1,n+1):
    psa[i] = psa[i - 1] + a[i-1]

mnt = float("inf")
ans = 0
for i in range(1, n-k+2):
    mnc = a[i+k-2] - a[i-1]
    if mnc < mnt:
        mnt = mnc
        ans = psa[i+k-1] - psa[i-1]
    elif mnc == mnt:
        ans = psa[i+k-1] - psa[i-1]

print(ans)