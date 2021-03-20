t = int(input())
for j in range(t):
    s = input()
    x = len(s)
    util = []
    sufarr = []
    for i in range(len(s)):
        util.append([s[i:len(s)],i])
    util.sort()
    for i in util:
        sufarr.append(i[1])

    n = len(sufarr)
    lcp = [0]*n
    inv = [0]*n

    for i in range(n):
        inv[sufarr[i]] = i

    k = 0

    for i in range(n):
        if inv[i] == n-1:
            k = 0
            continue
        j = sufarr[inv[i]+1]
        while i+k < n and j+k < n and s[i+k] == s[j+k]:
            k += 1

        lcp[inv[i]] = k

        if k > 0:
            k -= 1

    ans = x*(x+1)//2 - sum(lcp) + 1
    print(ans)