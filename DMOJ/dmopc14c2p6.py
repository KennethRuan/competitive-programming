from sys import stdin

input = stdin.readline

def query(x):
  s = 0
  while x > 0:
    s += bit[x]
    x -= x & -x
  return s

def update(k,v):
  while k <= n:
    bit[k] += v
    k += k & -k

n = int(input())
bit = [0 for i in range(n+1)]

a = list(map(int,input().split()))

#First is value, second is index in BIT
li = [[a[i],i+1] for i in range(len(a))]
li = sorted(li,key = lambda x: x[0],reverse = True)
b = int(input())

q = []
for i in range(b):
  q.append(list(map(int,input().split()))+[i])

#Queries are stored as, left, right, min, original index
q = sorted(q,key = lambda x: x[2],reverse = True)
ans = [-1 for i in range(b)]
#print(li)
#print(q)

ct2 = 0

for i in q:
  while ct2 < n and li[ct2][0] >= i[2]:
    update(li[ct2][1],li[ct2][0])
    ct2 += 1
  ans[i[3]] = query(i[1]+1)-query(i[0])
  

for i in ans:
  print(i)