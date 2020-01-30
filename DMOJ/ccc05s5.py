from sys import stdin
input = stdin.readline


def query(x):
    s = 0
    while x > 0:
        s += bit[x]
        x -= x & -x
    return s


def update(k, v):
    while k < t + 1:
        bit[k] += v
        k += k & -k


t = int(input())
bit = [0] * (t + 1)
inp = []
for i in range(t):
    inp.append([int(input()), i])
# 50 0, 100 1, 2 3
inp = sorted(inp)
scores = [0] * (t)
# 2 1 3, 50 2 0, 100 3 1
for i in range(t):
    scores[inp[i][1]] = i + 1
# ranking, order it came in

un = 0
total = 0
for i in range(t):
    un += 1
    total += un - query(scores[i])
    update(scores[i], 1)

print("%.2f" % round(total / t, 2))