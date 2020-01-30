from sys import stdin

input = stdin.readline


def query(x):
    s = 0
    while x > 0:
        s += bit[x]
        x -= x & -x
    return s

def update(k, v):
    while k <= n:
        bit[k] += v
        k += k & -k


n, b = map(int,input().split())
bit = [0 for i in range(n + 1)]

a = list(map(int, input().split()))

psa = [0 for i in range(n+1)]
s = 0
for i in range(n):
    s += a[i]
    psa[i+1] = s

# First is value, second is index in BIT
li = [[a[i], i + 1] for i in range(len(a))]
li = sorted(li, key=lambda x: x[0])

q = []
for i in range(b):
    q.append(list(map(int, input().split())) + [i])

# Queries are stored as, left, right, min, original index
q = sorted(q, key=lambda x: x[2])
ans = [-1 for i in range(b)]

c = 0

for i in q:
    while c < n and li[c][0] < i[2]:
        update(li[c][1], li[c][0])
        c += 1
    # print(i)
    # print(bit)
    ans[i[3]] = psa[i[1]] - psa[i[0]-1] - 2*(query(i[1]) - query(i[0]-1))
    # print(ans[i[3]])

for i in ans:
    print(i)