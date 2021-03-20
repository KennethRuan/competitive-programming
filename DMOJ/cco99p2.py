n = int(input())
for _ in range(n):
    m,k = list(map(int,input().split()))
    di = {}
    for i in range(m):
        s = input()
        if s not in di.keys():
            di[s] = 0
        di[s] += 1
    di = sorted(di.items(),key=lambda x:x[1],reverse = True)
    di.insert(0,("ecksdee",float("inf")))
    #print(di)

    if len(str(k)) >= 2:
        if str(k)[-1] == "3" and str(k)[-2:] != "13":
            print(str(k) + "rd most common word(s):")
        elif str(k)[-1] == "2" and str(k)[-2:] != "12":
            print(str(k) + "nd most common word(s):")
        elif str(k)[-1] == "1" and str(k)[-2:] != "11":
            print(str(k) + "st most common word(s):")
        else:
            print(str(k) + "th most common word(s):")
    else:
        if str(k) == "3":
            print(str(k) + "rd most common word(s):")
        elif str(k) == "2":
            print(str(k) + "nd most common word(s):")
        elif str(k) == "1":
            print(str(k) + "st most common word(s):")
        else:
            print(str(k) + "th most common word(s):")

    p = 0
    q = 0
    for i in range(1,len(di)):
        if di[i][1] == di[i - 1][1]:
            q += 1
        if di[i][1] < di[i-1][1]:
            p += q + 1
            q = 0
        if p == k:
            print(di[i][0])
    print()