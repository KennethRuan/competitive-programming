from collections import deque
from sys import stdin

#make visited a true false 2d array

input = stdin.readline


def bfs(s, e, visited, l, w):
    steps = [[100 for i in range(l)] for j in range(w)]
    steps[s[0]][s[1]] = 0
    visited[s[0]][s[1]] = True
    queue = deque([s])

    dir = [[1, 0], [-1, 0], [0, 1], [0, -1]]

    while queue:
        cur = queue.popleft()

        if steps[cur[0]][cur[1]] >= 60:
            return "#notworth"

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
    # print("queue ended")
    return "#notworth"

t = int(input())
for a in range(t):


    l, w = map(int, input().split())
    visited = [[False for x in range(l)]for y in range(w)]
    for i in range(w):

        row = list(input())[:-1:]

        for j in range(l):

            if row[j] == 'X':
                visited[i][j] = True
            elif row[j] == 'C':
                start = [i, j]
            elif row[j] == 'W':
                end = [i, j]
    print(bfs(start, end, visited, l, w))