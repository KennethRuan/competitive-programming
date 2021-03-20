import operator

n = int(input())
s = input()
li = []
c = 0
p = 0
for i in range(len(s)):

    if s[i] == "c":
        c += 1
    if s[i] == "p":
        p += 1
    if s[i] == "w":
        li.append([c+p,i,c,p])
        c = 0
        p = 0
    if i == len(s)-1:
        li.append([c + p, i, c, p])
li = sorted(li, key=lambda x:x[0],reverse = True)
# print(li)
ind = 0
cnt = 0
for i in li:
    cnt += 1
    if i[0] == li[0][0]:
        if i[1] < li[0][1]:
            ind = cnt
print(li[ind][3],li[ind][2])