from sys import stdin

input = stdin.readline

n,q = map(int,input().split())

def query(x,bit):
    s = 0
    while x > 0:
        s += bit[x]
        x -= x & -x
    return s

def update(k,v,bit,mn):
    while k <= mn:
        bit[k] += v
        k += k & -k


num = list(map(int,input().split()))

n_bit = [0 for i in range(n+1)]

for i in range(0,len(num)):
    update(i+1,num[i],n_bit,n)

c_bit = [0 for i in range(100001)]

for i in num:
    update(i,1,c_bit,100001)
#
# print(num)
# print(n_bit)
# print(c_bit)

for i in range(q):
    inp = input().split()
    if inp[0] == "C":
        update(query(int(inp[1]),n_bit)-query(int(inp[1])-1,n_bit),-1,c_bit,100001)
        update(int(inp[2]),1,c_bit,100001)
        update(int(inp[1]),int(inp[2])-query(int(inp[1]),n_bit)+query(int(inp[1])-1,n_bit),n_bit,n)
    if inp[0] == "S":
        print(query(int(inp[2]),n_bit)-query(int(inp[1])-1,n_bit))
    if inp[0] == "Q":
        print(query(int(inp[1]),c_bit))
#
# print(n_bit)
# print(c_bit)