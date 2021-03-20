tiles = int(input())
r = int(input())
c = int(input())

floor = []
rooms = []

rtiled = 0


def getRoom(i,j):
    if j in floor[i]:
        return 0
    floor[i].append(j)
    return 1 + (getRoom(i,j+1) if j < c - 1 else 0) + (getRoom(i,j-1) if j > 0 else 0) + (getRoom(i+1,j) if i < r - 1 else 0) + (getRoom(i-1,j) if i > 0 else 0)


for i in range(r):
    ar = input()
    row = []
    for j in range(len(ar)):
        if ar[j] == 'I':
            row.append(j)
    floor.append(row)

for i in range(r):
    for j in range(c):
        if j not in floor[i]:
            rooms.append(getRoom(i,j))

rooms.sort(reverse=True)

for i in rooms:
    if tiles >= i:
        rtiled += 1
        tiles -= i
    else:
        break
if rtiled == 1:
    print(str(rtiled)+" room, "+str(tiles)+" square metre(s) left over")
else:
    print(str(rtiled) + " rooms, " + str(tiles) + " square metre(s) left over")