chars = "1234567890()"
n = int(input())
for i in range(n):
    valid = True
    s = input()
    l = 0
    r = 0
    for j in range(len(s)):

        ok = False

        for k in chars:
            if s[j] == k:
                ok = True

        if ok:
            if s[j] == "(":
                l += 1
            if s[j] == ")":
                r += 1
            if r > l:
                valid = False
                break
        else:
            valid = False
            break
    if r != l:
        valid = False

    print("YES" if valid else "NO")