a,b = map(int,input().split())
s = input()
t = input()

lf = [False for _ in range(26)]
ind = [[] for _ in range(26)]
p = [0 for _ in range(26)]


def bs(c, p):
    l = 0
    ans = 0
    r = len(ind[c])-1
    while l <= r:
        m = (l+r)//2
        if ind[c][m] > p:
            ans = m
            r = m-1
        else:
            l = m+1
    return ind[c][ans]

for i, c in enumerate(s):
    ch = ord(c)-ord('a')
    ind[ch].append(i+1)

cur = -1
loops = 0
flag = True
for c in t:
    x = ord(c) - ord('a')
    if len(ind[x]) == 0:
        flag = False
        break
    pos = bs(x, cur)
    if cur < pos:
        cur = pos
    else:  # all indices have to be set to 0
        loops += 1
        for i in range(26):
            p[i] = 0
        cur = pos

if flag:
    print(loops*len(s) + cur)
else:
    print(-1)