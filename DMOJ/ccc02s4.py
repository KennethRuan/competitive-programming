m = int(input())
q = int(input())
t = []
names = [""]
for i in range(q):
    names.append(input())
    t.append(int(input()))

dp = [float("inf") for i in range(q+1)]
dp[0] = 0
order = [0 for i in range(q+1)]
sol = []
for i in range(1,q+1):
    for j in range(1,min(i,m)+1):
        if dp[i] > dp[i-j]+max(t[i-j:i]):
            dp[i] = dp[i-j]+max(t[i-j:i])
            order[i] = i-j

i = q
while i != 0:
    sol.append(names[order[i]+1:i+1])
    i = order[i]

print("Total Time: "+str(dp[q]))
for i in sol[::-1]:
    for j in i:
        print(j,end = " ")
    print()