cap = False
s = input()
ans = ""
for c in s:
    if cap:
        ans += c.upper()
    else:
        ans += c.lower()
    if c.isalpha():
        cap = not cap

print(ans)