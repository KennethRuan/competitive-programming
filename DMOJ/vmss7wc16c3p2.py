def bfs(s, e, g):
    visited = []
    queue = [s]
    while queue:
        cur = queue.pop(0)
        if cur == e:
            return True
        visited.append(cur)
        for z in g[cur]:
            if z not in visited:
                queue.append(z)
    return False

num = input().split()

n = int(num[0])
m = int(num[1])
a = int(num[2])
b = int(num[3])
temp = []
graph={}
for i in range(n+1):
    temp.append([])
for i in range(m):
    path = input().split(" ")
    temp[int(path[0])].append(int(path[1]))
    temp[int(path[1])].append(int(path[0]))
gen = ((i, temp[i]) for i in range(1,n+1))
graph = dict(gen)
if (bfs(a,b,graph)):
    print("GO SHAHIR!")
else:
    print("NO SHAHIR!")