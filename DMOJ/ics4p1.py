from itertools import permutations 
for i in sorted(set(map("".join, permutations(input())))): 
    print(i)