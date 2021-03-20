import heapq

def dijk(s, graph):
    sps = [float("inf") for i in range(n+1)]
    sps[s] = 0
    pq = [[0,s]]
    heapq.heapify(pq)
    visited = [False for i in range(n+1)]
    while pq:
        dist, node = heapq.heappop(pq)
        visited[node] = True
        for i in graph[node]:
            if not visited[i[0]]:
                if dist + i[1] < sps[i[0]]:
                    sps[i[0]] = dist + i[1]
                    heapq.heappush(pq,[sps[i[0]],i[0]])
    return sps

n,m,b,q = map(int,input().split())
graph = [[] for i in range(n+1)]
for i in range(m):
    x,y,z = map(int,input().split())
    graph[x].append([y,z])
    graph[y].append([x,z])
sps = dijk(b, graph)
for i in range(q):
    a = int(input())
    print(sps[a] if sps[a] < float("inf") else -1)