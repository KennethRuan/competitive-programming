n = int(input())

for i in range(n):
    li = list(map(int,input().split()))
    geo = True
    arith = True

    for j in range(len(li)):
        if(j+2 < len(li)):
            if (li[j] + li[j+2] == 2*li[j+1]) == False:
                arith = False
            if (li[j] * li[j+2] == li[j+1]**2) == False:
                geo = False

    if geo == True and arith == True:
        print("both")
    elif geo == True:
        print("geometric")
    elif arith == True:
        print("arithmetic")
    else:
        print("neither")