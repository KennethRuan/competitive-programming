from sys import stdin
from collections import deque

input = stdin.readline
n,m = list(map(int,input().split()))

edges = [[] for i in range(n+1)]

for i in range(m):
  a,b = map(int,input().split())
  edges[a].append(b)
  edges[b].append(a)

gen = ((i,edges[i]) for i in range(n+1))
graph = dict(gen)

#print(graph)
s,e = map(int,input().split())

def bfs(s,e):
  queue = deque([s])
  visited = [False for i in range(n+1)]
  visited[s] = True
  steps = [float("inf") for i in range(n+1)]
  steps[s] = 0
  3
  while queue:
    cur = queue.popleft()
    if cur == e:
      if steps[cur] <= 2:
        return "yay! no complaint."

    for i in graph[cur]:
      if visited[i] == False:
        visited[i] = True
        steps[i] = min(steps[cur]+1,steps[i])
        queue.append(i)
  return "aww man! whiny Alan."

print(bfs(s,e))