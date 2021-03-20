from collections import deque
from sys import stdin

input = stdin.readline

def bfs(sx, sy, bx , by, ex, ey, visited, x, y):
    queue = deque([[sx,sy,bx,by,0]])
    visited[sx][sy][bx][by] = True
    dr = [[-1, 0], [1, 0], [0, -1], [0, 1]]

    while queue:
        cur = queue.popleft()
        # print("Reached", cur[0], cur[1], "with box at", cur[2], cur[3], "in",
        #       steps[cur[0]][cur[1]][cur[2]][cur[3]], "steps")
        if cur[2] == ex and cur[3] == ey:
            return cur[4]

        for a in dr:
            nx = cur[0] + a[0]
            ny = cur[1] + a[1]
            if 0 <= nx < x and 0 <= ny < y:
                nbx = cur[2]
                nby = cur[3]
                if nx == cur[2] and ny == cur[3]:
                    nbx += a[0]
                    nby += a[1]
                if 0 <= nbx < x and 0 <= nby < y:
                    if not visited[nx][ny][nbx][nby]:
                        visited[nx][ny][nbx][nby] = True
                        queue.append([nx, ny, nbx, nby,cur[4]+1])
    return -1


y,x = map(int, input().split())
visited = [[[[False for a in range(y)] for b in range(x)] for c in range(y)] for d in range(x)]
sx = sy = bx = by = ex = ey = 99999999
for i in range(y):

    row = input()
    for j in range(x):
        if row[j] == "P":
            sx = j
            sy = i

        if row[j] == "B":
            bx = j
            by = i

        if row[j] == "X":
            ex = j
            ey = i

        if row[j] == "#":
            for a in range(x):
                for b in range(y):
                    visited[j][i][a][b] = True

if sx == 99999999 or sy == 99999999 or bx == 99999999 or by == 99999999 or ex == 99999999 or ey == 99999999:
    print("-1")
else:
    print(bfs(sx,sy,bx,by,ex,ey,visited,x,y))