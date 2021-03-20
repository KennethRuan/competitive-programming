n = int(input())
f = list(map(int,input().split()))
med = 0

for i in range(len(f)):
  med += f[i]

m = int(input())  

for i in range(m):
  a,d = map(int,input().split())
  med -= d
  if (f[a-1] + f[a]) < d+max(f[a-1],f[a]):
    med += d - min(f[a-1],f[a])
print(med)