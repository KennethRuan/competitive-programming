from collections import deque

inf = float("inf")
n,m = map(int,input().split())
g = [[] for i in range(n+1)]
c = [[inf for i in range(n+1)]for j in range(n+1)]
sps = [inf for i in range(n+1)]
for i in range(m):
    u,v,w = map(int,input().split())
    g[u].append(v)
    g[v].append(u)
    c[u][v] = min(c[u][v],w)
    c[v][u] = min(c[v][u],w)

q = deque([1])
sps[1] = 0
visited = [False for i in range(n+1)]
visited[1] = True
# print(g)
while q:
    cur = q.popleft()
    # print("cur",cur)
    # print(visited)
    # print(sps)
    for i in g[cur]:
        if not visited[i]:
            sps[i] = min(sps[i],sps[cur]+c[cur][i])
    mini = 0
    for i in range(1,n+1):
        if not visited[i]:
            if sps[i] < sps[mini]:
                mini = i
    if mini != 0:
        q.append(mini)
        visited[mini] = True
#
# print(sps)
for i in range(1,n+1):
    if sps[i] == inf:
        print(-1)
    else:
        print(sps[i])