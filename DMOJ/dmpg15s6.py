from collections import deque

def bfs():
    queue = deque([["APPLES", 1]])
    while queue:
        cur = queue.popleft()
        print(cur)
        for i in g[cur[0]]: # for each neighbour get the edge cost
            if (i[1] * cur[1]) - exc[i[0]] >= 0.000001: # if the (edge cost * the maximum apples we can get for our current fruit) is greater than the highest exchange rate of the other fruit
                if i[0] == "APPLES":
                    return "YAW"
                exc[i[0]] = (i[1] * cur[1])
                queue.append([i[0],exc[i[0]]])
    return "NAW"

# exc stores the highest exchange rate for that product in terms of apples
# the queue stores the exchange rate needed to get to that product i[1]


n,m = map(int,input().split())
g = {}
exc = {}
for i in range(n):
    temp = input()
    g[temp] = []
    exc[temp] = 0
exc["APPLES"] = 1

for i in range(m):
    temp = input().split()
    g[temp[0]].append([temp[1],float(temp[2])])

print(g)
print(bfs())

