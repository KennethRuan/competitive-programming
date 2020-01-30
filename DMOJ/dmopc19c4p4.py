import math
n = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))
p = list(map(int,input().split()))
if a[0] == b[0] and a[1] == b[1]:
    print("0")
else:
    print("1" if math.sqrt((a[0]-p[0])**2+(a[1]-p[1])**2) == math.sqrt((b[0]-p[0])**2+(b[1]-p[1])**2) else "-1")