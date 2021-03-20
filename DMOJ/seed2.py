import sys
l = 1
r = 2*(10**9)
while l < r:
    mid = (r+l)//2
    print(mid)
    sys.stdout.flush()
    a = input()
    if a == "OK":
        break
    elif a == "SINKS":
        l = mid
    else:
        r = mid