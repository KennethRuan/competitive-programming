n = int(input())
cards = [0 for i in range(100001)]
li = list(map(int,input().split()))

for i in li:
  cards[i] += i

p1 = 0
p2 = 0
for i in range(100001):
  temp = p1
  p1 = p2 + cards[i]
  p2 = max(p2,temp)

print(max(p2,p1))