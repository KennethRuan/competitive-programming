from collections import deque

def bfs(a,b):
    q = deque([0])
    visited = [False for i in range(26)]
    visited[0] = True
    while q:
        cur = q.popleft()
        if cur == 1:
            return ""
        for i in g[cur]:
            if not(cur == a and i == b) and not(cur == b and i == a) and not visited[i]:
                q.append(i)
                visited[i] = True
    return chr(a+ord("A"))+chr(b+ord("A"))


e = []
g = [[] for i in range(26)]
ans = []
while True:
    inp = input()
    if inp == "**":
        break
    a = ord(inp[0]) - ord("A")
    b = ord(inp[1]) - ord("A")
    e.append([a,b])
    g[a].append(b)
    g[b].append(a)

cnt = 0

for a,b in e:
    t = bfs(a,b)
    if t != "":
        cnt += 1
        ans.append(t)

for i in ans:
    print(i)
print("There are "+str(cnt)+" disconnecting roads.")