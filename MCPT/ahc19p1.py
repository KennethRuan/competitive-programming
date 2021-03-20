import math
def is_cube_root(x):
    x = abs(x)
    return int(math.pow(round(math.pow(x,1.0/3.0)),3)) == x

def is_square_root(x):
    if x < 0:
        return False
    elif x >= 0 and int(math.pow(round(math.sqrt(x)),2)) == x:
        return True

i = int(input())
if is_cube_root(i) and is_square_root(i):
    print("Perfectly Perfect")
elif is_cube_root(i):
    print("Kinda Perfect")
elif is_square_root(i):
    print("Somewhat Perfect")
else:
    print("Not Perfect At All")