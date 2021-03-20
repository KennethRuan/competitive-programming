input()
li = list(map(int,input().split()))

dict = {}

for i in range(len(li)):
    if li[i] not in dict.keys():
        dict[li[i]] = 0
    dict[li[i]] += 1

mode = []
max = -10000000
for i in dict.keys():
    if dict[i] > max:
        mode = []
        mode.append(i)
        max = dict[i]
    elif dict[i] == max:
        mode.append(i)

mode = sorted(mode)

for i in range(len(mode)):
    print(mode[i], end = " ")