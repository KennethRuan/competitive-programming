a = int(input())
for i in range(a):
   b = int(input())
   max = 0
   c = input().split(' ')
   d = input().split(' ')
   for j in range(b):
       for k in range(b):
           if c[j] == d[k]:
                   if max < k-j:
                       max = k-j
   print("The maximum distance is", max)