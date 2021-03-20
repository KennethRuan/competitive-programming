def bfs(graph,n):

    queue = [1]
    visited = [False for i in range(n + 1)]
    shortest = [10001 for i in range(n+1)]
    shortest[1] = 1
    short = 10001
    reachable = 'Y'

    while queue:
        cur = queue.pop(0)

        if not graph[cur]:
            short = min(short,shortest[cur])

        visited[cur] = True
        for z in graph[cur]:
            if shortest[cur]+1 < shortest[z]:
                shortest[z] = shortest[cur]+1
            if not visited[z]:
                queue.append(z)

    for i in visited[1::]:
        if not i:
            reachable = 'N'

    print(reachable)
    print(short)

n = int(input())

gen = [[] for i in range(n)]

for i in range(n):
    a = list(map(int,input().split(" ")))[1::]
    for j in a:
        gen[i].append(j)

graph = dict((i+1,gen[i]) for i in range(n))



bfs(graph,n)