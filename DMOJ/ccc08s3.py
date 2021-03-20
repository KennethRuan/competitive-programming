from collections import deque

def bfs(graph,visited,r,c):
    steps = [[0 for i in range(c)] for i in range(r)]
    steps[0][0] = 1
    q = deque([[0,0]])
    visited[0][0] = True

    while q:
        y,x = q.popleft()
        # print(y,x)
        if x == c-1 and y == r-1:
            return steps[r-1][c-1]

        dir = []
        if graph[y][x] == "+":
            dir = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        if graph[y][x] == "|":
            dir = [[1, 0], [-1, 0]]
        if graph[y][x] == "-":
            dir = [[0, 1], [0, -1]]

        for i in dir:
            ny = y+i[0]
            nx = x+i[1]
            if r > ny >= 0:
                if c > nx >= 0:
                    if not visited[ny][nx]:
                        q.append([ny, nx])
                        visited[ny][nx] = True
                        steps[ny][nx] = steps[y][x] + 1

    return -1

t = int(input())
for a in range(t):
    r = int(input())
    c = int(input())
    visited = [[False for i in range(c)]for j in range(r)]
    graph = [[] for i in range(r)]
    for i in range(r):
        row = input()
        for j in range(c):
            if row[j] == "*":
                visited[i][j] =  True
            graph[i].append(row[j])
    print(bfs(graph,visited,r,c))