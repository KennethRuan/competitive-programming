n,m,a,b,c = map(int,input().split())
opp = list(map(int,input().split()))
for i in list(map(int,input().split())):
  if opp[i-1] == 1:
    m += a
  else:
    m -= b

print(m)