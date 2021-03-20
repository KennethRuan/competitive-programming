n = int(input())
num = "0123456789"
for i in range(n):
    s = input().lower()
    for j in s:
        if j == 'a':
            print("Hi!", end=" ")
        elif j == 'e':
            print("Bye!", end=" ")
        elif j == 'i':
            print("How are you?", end=" ")
        elif j == 'o':
            print("Follow me!", end=" ")
        elif j == 'u':
            print("Help!", end=" ")
        else:
            for _ in num:
                if j == _:
                    print("Yes!",end = " ")
                    break
    print()