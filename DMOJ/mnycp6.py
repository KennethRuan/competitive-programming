from sys import stdin

input = stdin.readline

bit = [0 for i in range(10001)]
ref = {}

#BIT stores the psa of values
#ref stores dictionary of names and corresponding index

def query(x):
  s = 0
  while x > 0:
    s += bit[x]
    x -= x & -x
  return s

def update(k,v):
  while k <= 10001:
    bit[k] += v
    k += k & -k

def value(x):
  s = 0
  for i in x:
    s += ord(i)-96
  return s

c = int(input())

for i in range(c):
  inp = input().split()
 
  if inp[0] == "A":
    if inp[1] in ref.keys():
      print("Can't add ", inp[1])
    else:
      update(len(ref)+1,value(inp[1]))
      ref[inp[1]] = len(ref)+1

  if inp[0] == "S":
    x_ind = ref[inp[1]]
    y_ind = ref[inp[2]]
    x_val = query(ref[inp[1]])-query(ref[inp[1]]-1)
    y_val = query(ref[inp[2]])-query(ref[inp[2]]-1)
    update(x_ind,y_val-x_val)
    update(y_ind,x_val-y_val)
    ref[inp[1]] = y_ind
    ref[inp[2]] = x_ind

  if inp[0] == "M":
    a = query(ref[inp[2]])
    b = query(ref[inp[1]])
    if a > b:
      print(a-query(ref[inp[1]]-1)) 
    else:
      print(b-query(ref[inp[2]]-1))
    #potential issue if first inp isn't greater than second
  
  if inp[0] == "R":
    x_ind = ref[inp[1]]
    update(x_ind, value(inp[2])-query(x_ind)+query(x_ind-1))
    del ref[inp[1]]
    ref[inp[2]] = x_ind

  if inp[0] == "N":
    print(len(ref))