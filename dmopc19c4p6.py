import math
n,q = map(int,input().split())
t = [0]+list(map(int,input().split()))
for i in range(q):
    inp = list(map(int,input().split()))
    # print(t)
    if inp[0] == 1:
        print(t[inp[1]])

    if inp[0] == 2:
        cook = True
        for j in range(inp[1],inp[2]+1):
            if t[j] < inp[3]:
                cook = False
        if cook:
            for j in range(inp[1],inp[2]+1):
                t[j] -= inp[3]

    if inp[0] == 3:
        for j in range(inp[1],inp[2]+1):
            t[j] = inp[3]-inp[2]+j

    if inp[0] == 4:
        for j in range(inp[1],inp[2]+1):
            t[j] = math.floor(math.sqrt(t[j]))
