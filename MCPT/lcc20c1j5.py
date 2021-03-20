from collections import deque
from math import sqrt
from sys import stdin

input = stdin.readline

mxc = int(1e9)

n = int(input())
inp = []
cc = []
se = set()
for _ in range(n):
    x, y, r = map(int, input().split())
    inp.append([x,y,r])
    for i in range(x-r, x+r+1):
        se.add(i)

for v in se:
    cc.append(v)
cc.sort()

da = [[] for _ in range(len(cc))]

def bs(cc, x):
    l = 0
    u = len(cc)
    while l <= u:
        m = (l+u)//2
        if cc[m] == x:
            return m
        elif x < cc[m]:
            u = m-1
        else:
            l = m+1
    return "oop"

for _ in range(n):
    x, y, r = inp[_]
    for i in range(x-r, x+r+1):
        s = int(sqrt(r**2 - (i-x)**2))
        ind = bs(cc, i)
        da[ind].append([-s+y, s+y])

orz = 0
for x in range(len(da)):
    da[x].sort()
    stack = deque([])
    stack.append(da[x][0])
    for i in range(1, len(da[x])):
        top = stack[-1]
        if da[x][i][0] > top[1]:
            stack.append(da[x][i])
        elif top[1] < da[x][i][1]:
            top[1] = da[x][i][1]
            stack.pop()
            stack.append(top)

    for i in stack:
        orz += i[1] - i[0] + 1

print(orz)