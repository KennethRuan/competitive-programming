def zeros(n):
    count = 0
    i=5
    while (n//i>=1): 
        count += n//i 
        i *= 5

    return count 

def bs():
  l = 1
  h = q * 10 
  while (l<h):
    mid = l + (h-l)//2
    zero = zeros(mid)
    if zero >= q: 
      h = mid;
    else:
      l = mid + 1
    
  return l if (zeros(l) == q) else "No solution"

q = int(input())
print(bs())