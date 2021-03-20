valid = True
letters = ['I', 'O', 'S', 'H', 'Z', 'X', 'N']
s = input()
for i in s:
    if (i not in letters):
        valid = False
        
if valid:
    print("YES")
else:
    print("NO")