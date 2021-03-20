goal = int(input())
clubs = []
for i in range(int(input())):
    clubs.append(int(input()))
values = [0] + [99999 for i in range(goal)]

for i in range(goal):
    for j in clubs:
        if i+j <= goal:
            if values[i+j] > values[i]+1:
                values[i+j] = values[i]+1

if values[goal] == 99999:
    print("Roberta acknowledges defeat.")
else:
    print("Roberta wins in " + str(values[goal]) + " strokes.")