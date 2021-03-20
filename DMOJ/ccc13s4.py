from sys import stdin
from collections import deque
input = stdin.readline

def bfs(s,e,graph):
    queue=deque([s])
    visited = [False for i in range(n+1)]
    while queue:
        cur = queue.popleft()
        if cur == e:
            return True
        for i in graph[cur]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True
    return False

lmi = lambda: list(map(int,input().split()))

n,m = lmi()

graph = [[]for i in range(n+1)]

for i in range(m):
    x,y = lmi()
    graph[x].append(y)

p,q = lmi()

if bfs(p,q,graph):
    print("yes")
elif bfs(q,p,graph):
    print("no")
else:
    print("unknown")