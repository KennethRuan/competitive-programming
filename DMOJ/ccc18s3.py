from sys import stdin
from collections import deque

input = stdin.readline

n,m = map(int,input().split())
visited = [[False for i in range(m)]for i in range(n)]
ill = [[False for i in range(m)]for i in range(n)]
di = [[0,1],[0,-1],[1,0],[-1,0]]
d = []
cam = []
sr = 0
sc = 0
g = []

for i in range(n):
    row = input()
    g.append([])
    for j in range(len(row)-1):
        if row[j] == "W":
            visited[i][j] = True
        if row[j] == "C":
            cam.append([i,j])
        if row[j] == "S":
            sr = i
            sc = j
        if row[j] == ".":
            d.append([i,j])
        g[i].append(row[j])

for i,j in cam:
    for _ in di:
        r,c = i+_[0],j+_[1]
        while not visited[r][c]:
            if g[r][c] != "U" and g[r][c] != "D" and g[r][c] != "L" and g[r][c] != "R":
                ill[r][c] = True
            r += _[0]
            c += _[1]
    ill[i][j] = True

ans = [[float("inf") for i in range(m)]for i in range(n)]
ans[sr][sc] = 0
q = deque()
if not ill[sr][sc]:
    q.append([sr,sc])

while q:
    r,c = q.popleft()
    if g[r][c] == "S" or g[r][c] == ".":
        for _ in di:
            if ans[r][c]+1 < ans[r+_[0]][c+_[1]] and not visited[r+_[0]][c+_[1]] and not ill[r+_[0]][c+_[1]]:
                ans[r + _[0]][c + _[1]] = ans[r][c]+1
                q.append([r+_[0],c+_[1]])

    if g[r][c] == "U":
        if ans[r][c] < ans[r - 1][c] and not visited[r - 1][c] and not ill[r - 1][c]:
            ans[r - 1][c] = ans[r][c]
            q.append([r - 1, c])
    if g[r][c] == "D":
        if ans[r][c] < ans[r + 1][c] and not visited[r + 1][c] and not ill[r + 1][c]:
            ans[r + 1][c] = ans[r][c]
            q.append([r + 1, c])
    if g[r][c] == "L":
        if ans[r][c] < ans[r][c - 1] and not visited[r][c - 1] and not ill[r][c - 1]:
            ans[r][c - 1] = ans[r][c]
            q.append([r, c - 1])
    if g[r][c] == "R":
        if ans[r][c] < ans[r][c + 1] and not visited[r][c + 1] and not ill[r][c + 1]:
            ans[r][c + 1] = ans[r][c]
            q.append([r, c + 1])

for i in d:
    print(ans[i[0]][i[1]] if ans[i[0]][i[1]] != float("inf") else -1)
#
# for i in visited:
#     print(i)