a = int(input())
li = []
for i in range(a):
  li.append(int(input()))
li = sorted(li)
prod = 1
pendn = False
pendnum = 0
zn = 0
znum = -6
for i in range(a):
  if prod * li[i] < prod:
    zn += 1
    if li[i] > znum:
      znum = li[i]
    if li[i] < 0:
      if pendn == True:
        prod *= pendnum * li[i]
        pendn = False
      elif pendn == False:
        pendn = True
        pendnum = li[i]
  else:
    prod *= li[i]

if len(li) == 1:
  prod = li[0]
if zn == len(li):
  prod = znum
print(prod)