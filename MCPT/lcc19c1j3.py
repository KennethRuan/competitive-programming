input()
school = list(map(int,input().split(" ")))
mcpt = list(map(int,input().split(" ")))
school = sorted(school)

for i in range(len(mcpt)):
    l = 0
    r = len(school) - 1
    gb = True
    while l <= r:
        mid = l + (r - l)//2
        if school[mid] == mcpt[i]:
            gb = False
            break
        elif mcpt[i] < school[mid]:
            r = mid - 1
        elif mcpt[i] > school[mid]:
            l = mid + 1

    if gb:
        print("Good")
    else:
        print("baf")