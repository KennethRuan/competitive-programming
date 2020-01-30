n,m,q = map(int,input().split())
ev = [0] + list(map(int,input().split()))
for i in range(q):
    money = m
    inp = list(map(int,input().split()))
    b = 0
    for j in range(inp[0],inp[1]+1):
        if money+ev[j] >= 0:
            money += ev[j]
        else:
            b+= 1
            money = 0
    print(money, b)