friend_total =[]
friends=[]
searching = False
location_one = -1
location_two = -1
completed = []
cycle = int(input())
person = -1
total_wait = 0
friend_num = -1

data = []

def calculate_wait(location_one,location_two):
    total_wait = 0
    subtract = data[location_one:location_two].count("W")
    for y in range(0, location_two - location_one):
        if data[y + location_one] == "W":
            total_wait += data[y + location_one + 1]
        elif data[y +location_one] == "R" or data[y +location_one] == "S":
            total_wait += 1
    return(total_wait - subtract)

for x in range(0,cycle):
    data.append(input())

data = (" ".join(data).split(" "))

for i in data:
    if i == " ":
        data.remove(" ")

for x in range(0,len(data)):

    try:
        data[x] = int(data[x])
    except:
        pass

for x in range(0,len(data)):
    if data[x] == "R" or data[x] == "S":
        friends.append(data[x+1])

friends = list(set(friends))
friends = sorted(friends)

while len(completed) < len(friends):
    searching = False
    location_two = -1
    location_one = -1
    person = friends[friend_num]
    friend_num += 1
    above = "inactive"
    for x in range(0,len(data)):

        if isinstance(x,int):
            if data[x] not in completed and data[x-1] == "R" and searching != True and data[x] == friends[friend_num]:
                location_one = x
                searching = True
                above = "active"

        if isinstance(x,int):
            if data[x] not in completed and data[x-1] == "R" and searching != True and above != "active":
                person == friends[friend_num]

        if searching:
            if x != location_one and data[x] == friends[friend_num] and location_two == -1 and data[x-1] == "S":
                location_two = x
                wait_calculate = True

        if location_one != -1 and location_two != -1 and wait_calculate == True:
            total_wait += calculate_wait(location_one,location_two)
            searching = False
            location_one = -1
            location_two = -1

        if total_wait > 0:
            wait_calculate = False

        if x == (len(data)-1):
            if location_two == -1 and location_one != -1:
                total_wait = -1
            friend_total.append([friends[friend_num],total_wait])
            completed.append(friends[friend_num])
            total_wait = 0

friend_total = sorted(friend_total, key=lambda x : x[0])

for x in range(len(friend_total)):
    print(str(friend_total[x][0]) +" "+ str(friend_total[x][1]))