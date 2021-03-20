n = input()
arr = list(map(int,list(input())))
state = 1
flips = 0
for i in range(len(arr)-1,-1,-1):
    if state == arr[i]:
        flips += 1
        state ^= 1

print(flips)