def checkWord(word,r,c): #r,c are the values in the grid
    for i in dir:
        if i[0] > 0 and n-len(word) >= c:
            if i[1] > 0 and m - len(word) >= r:
                for j in range(len(word)):
                    if grid[r+j][c+j] == word[j]:
                        check = True
                    else:
                        check = False
                        break
                if check == True:
                    return True

            if i[1] < 0 and r - (len(word)-1) >= 0:
                for j in range(len(word)):
                    if grid[r-j][c+j] == word[j]:
                        check = True
                    else:
                        check = False
                        break
                if check == True:
                    return True
            if i[1] == 0:
                for j in range(len(word)):
                    if grid[r][c+j] == word[j]:
                        check = True
                    else:
                        check = False
                        break
                if check == True:
                    return True


        elif i[0] < 0 and c - (len(word)-1) >= 0:
            if i[1] > 0 and m - len(word) >= r:
                for j in range(len(word)):
                    if grid[r + j][c - j] == word[j]:
                        check = True
                    else:
                        check = False
                        break
                if check == True:
                    return True

            if i[1] < 0 and r - (len(word)-1) >= 0:
                for j in range(len(word)):
                    if grid[r - j][c - j] == word[j]:
                        check = True
                    else:
                        check = False
                        break
                if check == True:
                    return True
            if i[1] == 0:
                for j in range(len(word)):
                    if grid[r][c - j] == word[j]:
                        check = True
                    else:
                        check = False
                        break
                if check == True:
                    return True

        elif i[0] == 0:
            if i[1] > 0 and m - len(word) >= r:
                for j in range(len(word)):
                    if grid[r + j][c] == word[j]:
                        check = True
                    else:
                        check = False
                        break
                if check == True:
                    return True
            if i[1] < 0 and r - (len(word)-1) >= 0:
                for j in range(len(word)):
                    if grid[r-j][c] == word[j]:
                        check = True
                    else:
                        check = False
                        break
                if check == True:
                    return True
    return False
dir = [[-1,-1],[0,-1],[1,-1],[1,0],[1,1],[0,1],[-1,1],[-1,0]]


cases = int(input())
for i in range(cases):
    m,n = map(int,input().split())
    grid = [[] for a in range(n)]
    words = []
    #Fills grids and words
    for j in range(m):
        for x in input():
            grid[j].append(x.lower())
    for j in range(int(input())):
        words.append(input().lower())
    #List of location of words
    words_loc = [[999,999]for j in range(len(words))]

    for a in range(m):
        for b in range(n):
            for j in range(len(words)):
                check = checkWord(words[j],a,b)
                if (check == True):
                    if (a+1 < words_loc[j][0]) or (a+1 == words_loc[j][0] and b+1 < words_loc[j][1]):
                        words_loc[j][0] = a+1
                        words_loc[j][1] = b+1

    for j in words_loc:
        print(j[0],j[1])
    print()