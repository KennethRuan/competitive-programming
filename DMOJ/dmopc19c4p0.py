s1 = input()
s2 = input()
d = 0
for i in range(len(s1)):
    if (s1[i] != s2[i]):
        d += 1

if d > 1 or d == 0:
    print("LARRY IS DEAD!")
else:
    print("LARRY IS SAVED!")