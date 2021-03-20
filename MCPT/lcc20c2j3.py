n = int(input())
a = list(map(int,input().split()))

mx = 0
ans = 0
for x in a:
    mx = max(x,mx)
    ans += mx - x
    
print(ans)