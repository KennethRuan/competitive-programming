from collections import deque

def bfs(s,e,graph,sep,visited):
  queue = deque([s])
  sep[s] = -1
  while queue:
    cur = queue.popleft()
    visited[cur] = True
    if cur == e:
      print("Yes",sep[cur])
      return 0
    i = graph[cur]
    if not visited[i]:
      queue.append(i)
      sep[i] = sep[cur]+1
      visited[cur] = True
  print("No")

a = int(input())
gen = []
for i in range(a):
  gen.append(list(map(int,input().split())))
graph = dict((gen[i][0],gen[i][1])for i in range(a))
sep = dict((gen[i][0],float("inf"))for i in range(a))
while True:
  s,e = map(int,input().split())
  visited = dict((gen[i][0],False)for i in range(a))
  if s == 0 and e == 0:
    break
  else:
    bfs(s,e,graph,sep,visited)