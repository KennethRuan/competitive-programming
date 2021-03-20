import heapq
from sys import stdin

input = stdin.readline

k,n,m = map(int,input().split())
g = [[] for i in range(n+1)]
for i in range(m):
  a,b,t,h = map(int,input().split())
  g[a].append([b,t,h]) #node to visit, time, dmg
  g[b].append([a,t,h])
s,e = map(int,input().split())

sps = [[float("inf") for i in range(k)]for i in range(n+1)]
sps[s][0] = 0
inq = [[False for i in range(k)]for i in range(n+1)]
inq[s][0] = True
q = [[0,s,0]] #Time, current node, hull damage
heapq.heapify(q)
while q:
  t, node, h = heapq.heappop(q)
  inq[node][h] = False
  for i in g[node]:
      if (h+i[2] < k):
        if sps[i[0]][h+i[2]] > sps[node][h]+i[1]:
          sps[i[0]][h+i[2]] = sps[node][h]+i[1]
          if not inq[i[0]][h+i[2]]:
            heapq.heappush(q,[sps[i[0]][h+i[2]],i[0],h+i[2]])
            inq[i[0]][h+i[2]] = True
# for i in sps:
#   print(i)
opt = min(sps[e])
print (opt if opt<float("inf") else -1)