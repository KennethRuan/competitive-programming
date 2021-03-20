input = input().split(" ")
start = int(input[0])
days = int(input[1])
calendar = []
for i in range(start-1):
    calendar.append("   ")
for i in range(days):
    calendar.append(" "*(3-len(str(i+(1)))) + str(i+1))
print("Sun Mon Tue Wed Thr Fri Sat",end="\n")
for i in range(len(calendar)):
    if (i+1)%7 == 0:
        print(calendar[i], end="\n")
    else:
        if (i+1) != len(calendar):
            print(calendar[i]+" ", end="")
        else:
            print(calendar[i])