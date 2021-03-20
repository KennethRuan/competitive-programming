from sys import stdin
input = stdin.readline

m = list(map(int,input().split()))[1]
li = list(map(int,input().split()))
p = [0]
pr = [0]
s = 0
for i in range(len(li)):
  s += li[i]
  p.append(s)
s = 0
for i in range(len(li)):
  s+= li[-i-1]
  pr.append(s)

rev = 1

biggest = 0
big_here = 0
big_elem = float("-inf")
for j in li:
  big_here = max(big_here+j,0)
  biggest = max(big_here,biggest)
  big_elem = max(big_elem,j)
if biggest == 0:
  biggest = big_elem

lir = li[::-1]

for i in range(m):
  inp = input().split()
  if inp[0] == "REVERSE":
    temp = li
    li = lir
    lir = temp
    rev *= -1
  if inp[0] == "GET-SUM":
    if rev == 1:
      print(p[int(inp[2])+int(inp[1])-1]-p[int(inp[1])-1])
    if rev == -1:
      print((pr[int(inp[1])-1+int(inp[2])])-pr[int(inp[1])-1])
  if inp[0] == "MAX-SUM":
    print(biggest)