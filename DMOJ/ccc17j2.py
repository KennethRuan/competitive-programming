num = input()
shift = int(input())
total = []

for x in range(shift+1):
  total.append(int(str(num)+str("0"*x)))

print(sum(total))