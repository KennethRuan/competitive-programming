from collections import deque


def bfs(sx, sy, ex, ey, visited, steps, x, y):
    queue = deque([[sx,sy,0,0]])
    steps[sx][sy][3][3] = 0
    visited[sx][sy][3][3] = True
    dr = [[-1, 0], [1, 0], [0, -1], [0, 1], [1, -1], [1, 1], [-1, 1], [-1, -1], [0, 0]]

    while queue:
        cur = queue.popleft()
        # print("Reached", cur[0], cur[1], "with a velocity of", cur[2], cur[3], "in",
        #       steps[cur[0]][cur[1]][cur[2] + 3][cur[3] + 3], "steps")
        if cur[0] == ex and cur[1] == ey:
            return "Optimal solution takes " + str(steps[cur[0]][cur[1]][cur[2]+3][cur[3]+3]) + " hops."

        for a in dr:
            nxv = cur[2] + a[0]
            nyv = cur[3] + a[1]
            if -4 < nxv < 4 and -4 < nyv < 4:
                nx = cur[0] + nxv
                ny = cur[1] + nyv
                if 0 <= nx < x and 0 <= ny < y:
                    if not visited[nx][ny][nxv+3][nyv+3]:
                        visited[nx][ny][nxv+3][nyv+3] = True
                        steps[nx][ny][nxv+3][nyv+3] = min(steps[cur[0]][cur[1]][cur[2]+3][cur[3]+3]+1, steps[nx][ny][nxv+3][nyv+3])
                        queue.append([nx, ny, nxv, nyv])
    return "No solution."

n = int(input())
for i in range(n):
    x, y = map(int, input().split())
    sx, sy, ex, ey = map(int, input().split())
    visited = [[[[[] for a in range(7)] for b in range(7)] for c in range(y)] for d in range(x)]
    steps = [[[[float("inf") for a in range(7)]for b in range(7)]for c in range(y)]for d in range(x)]
    p = int(input())
    for j in range(p):
        obx1, obx2, oby1, oby2 = map(int,input().split())
        for a in range(obx1,obx2+1):
            for b in range(oby1,oby2+1):
                for k in range(7):
                    for l in range(7):
                        visited[a][b][k][l] = True
    print(bfs(sx,sy,ex,ey,visited,steps,x,y))