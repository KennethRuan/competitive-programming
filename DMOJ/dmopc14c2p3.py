a = int(input())
e = sorted(list(map(int,input().split(" "))),reverse=True)
l = sorted(list(map(int,input().split(" "))))
total = 0
for i in range(a):
    total += e[i]*l[i]
print(total)