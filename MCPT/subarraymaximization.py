n = int(input())
arr = list(map(int,input().split()))
mx = 0
msf = 0
me = -1000000000
for i in arr:
    msf += i
    if msf < 0:
        msf = 0
    mx = max(mx,msf)
    me = max(me,i)

if me < 0:
    print(me)
else:
    print(mx)