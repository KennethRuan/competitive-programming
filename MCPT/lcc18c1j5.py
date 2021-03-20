from collections import deque
from sys import stdin

input = stdin.readline


def bfs(s, e, visited, l, w):
    steps = [[0 for i in range(l)] for j in range(w)]
    visited[s[0]][s[1]] = True
    queue = deque([s])

    dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]

    while queue:
        cur = queue.popleft()

        if cur == e:
            return steps[cur[0]][cur[1]]

        for i in dir:
            nw = cur[0]+i[0]
            nl = cur[1]+i[1]
            if 0 <= nw < w and l > nl >= 0:
                if not visited[nw][nl]:
                    visited[nw][nl]=True
                    queue.append([nw, nl])
                    steps[nw][nl] = steps[cur[0]][cur[1]] + 1

    return "There is no path, Andy!"

t = int(input())
visited = [[False for x in range(t)]for y in range(t)]
for i in range(t):

    row = list(input())[:-1:]

    for j in range(t):

        if row[j] == '#':
            visited[i][j] = True
        elif row[j] == 'S':
            start = [i, j]
        elif row[j] == 'E':
            end = [i, j]
print(bfs(start, end, visited, t, t))