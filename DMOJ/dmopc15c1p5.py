from sys import stdin
input = stdin.readline
w,h,n = map(int,input().split())
psa = [[0 for i in range(w+1)] for j in range(h+1)] 

for i in range(1,h+1):
  row = list(map(int,input().split()))
  for j in range(1,w+1):
    psa[i][j] = psa[i][j-1] + psa[i-1][j] - psa[i-1][j-1] + row[j-1]

f = []
for i in range(1, w+1):
  f.append((i, n//i))
  f.append((n//i, i))

ans = 0
for i in range(1, h+1):
  for j in range(1, w+1):
    for a, b in f:
      if i-a+1 > 0 and j - b +1 > 0:
        ans = max(ans, psa[i][j] - psa[i-a][j] - psa[i][j-b] + psa[i-a][j-b])
        
print(ans)