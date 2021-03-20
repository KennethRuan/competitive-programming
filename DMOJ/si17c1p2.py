n,k = map(int,input().split())
fish = list(map(int,input().split()))
ms = [0]*(n+k+1)
for i in range(n-1,-1,-1):
    ms[i] = max(fish[i]+ms[i+k+1],ms[i+1])
print(ms[0])