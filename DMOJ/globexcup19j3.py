n,k = map(int,input().split())
planets = []
for i in range(n):
  p,s = input().split()
  planets.append([p,int(s)])

planets = sorted(planets, key = lambda x: x[1])

final = []
for i in range(len(planets)):
  c1 = True
  c2 = True
  if i-1 >= 0:
    if abs(planets[i-1][1]-planets[i][1]) <= k:
      c1 = False
  if i+1 < len(planets):
    if abs(planets[i+1][1]-planets[i][1]) <= k:
      c2 = False
  if c1 and c2:
    final.append(planets[i][0])

for i in sorted(final):
  print(i,end = " ")