from collections import deque
def bfs_knight(s,e):
    visited = [[0 for i in range(8)]for j in range(8)]
    hops = [[100 for i in range(8)]for j in range(8)]
    visited[s[0]][s[1]] = 1
    hops[s[0]][s[1]] = 0
    queue = deque([s])
    dir = [[-2,1],[-2,-1],[-1,2],[-1,-2],[1,-2],[1,2],[2,1],[2,-1]]
    while queue:
        cur = queue.popleft()
        if cur == e:
            return hops[cur[0]][cur[1]]
        for i in dir:
            if 0 <= cur[0]+i[0] <= 7 and 0 <= cur[1]+i[1] <= 7:
                if visited[cur[0]+i[0]][cur[1]+i[1]] == 0:
                    visited[cur[0]+i[0]][cur[1]+i[1]] = 1
                    hops[cur[0]+i[0]][cur[1]+i[1]] = min(hops[cur[0]][cur[1]]+1,hops[cur[0]+i[0]][cur[1]+i[1]])
                    queue.append([cur[0]+i[0],cur[1]+i[1]])


start = list(map(int,input().split()))
end = list(map(int,input().split()))
start[0]-=1
start[1]-=1
end[0]-=1
end[1]-=1

print(bfs_knight(start,end))