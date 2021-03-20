n = int(input())
for _ in range(n):
    s = list(map(int, input().split()))
    s = sorted(s)
    a,b,c = s[0],s[1],s[2]
    if a**2 + b**2 > c**2:
        print("A")
    elif a**2 + b**2 == c**2:
        print("R")
    else:
        print("O")