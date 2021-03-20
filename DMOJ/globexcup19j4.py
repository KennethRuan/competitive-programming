n,m,k = map(int,input().split())
d = {}
for i in list(map(int,input().split())):
  if i not in d.keys():
    d[i] = 1
  else:
    d[i] += 1

li = []
for i in sorted(d,key = lambda x: d[x],reverse = True):
  li.append([i,d[i]])

c = 0
s = 0
for i in li:
  if c + i[1] <= k:
    c += i[1]
    s += ((i[1]-1)*i[1])//2
  else:
    s += ((k-c-1)*(k-c))//2
    break
print(s)