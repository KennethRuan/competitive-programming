from sys import stdin
input = stdin.readline

n = int(input())
p = list(map(int,input().split()))
tot = sum(p)
steps = []

def test(k):
    arr = p[:]
    arr[0] -= k
    arr[n-1] -= k
    for i in range(n-1):
        arr[i+1] -= arr[i]
        if arr[i+1] < 0:
            return False
    return arr[n-1] == 0

def serve(k):
    arr = p[:]
    arr[0] -= k
    arr[n-1] -= k
    for i in range(k):
        print(0,n-1)

    for i in range(n-1):
        arr[i+1] -= arr[i]
        for j in range(arr[i]):
            print(i,i+1)

s = False

for i in range(min(p[0],p[n-1])+1):
    if test(i):
        print("YES")
        print(tot//2)
        serve(i)
        s = True
        break

if not s:
    print("NO")