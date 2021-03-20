from collections import deque

def sum(str):
    s = 0
    for i in str:
        s += int(i)
    return s

n = int(input())
q = deque([[n,0]])
while q:
    n,s = q.popleft()
    if n == 1:
        print(s)
        break
    else:
        q.append([n//sum(str(n)),s+1])
        q.append([n-1,s+1])