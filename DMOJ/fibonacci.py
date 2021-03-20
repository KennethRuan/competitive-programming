def fib(n):
  m = [[1,1],
       [1,0]]
  if n == 0:
    return 0
  power(m,n-1)
  return m[0][0]

def power(m,p):
  if p == 0 or p == 1:
    return;
  f = [[1,1],
       [1,0]]
  power(m,p//2)
  mult(m,m)
  # print(m)
  if p%2 == 1:
    mult(m,f)

def mult(m,x):
  a = (m[0][0]*x[0][0]+m[0][1]*x[1][0]) % 1000000007
  b = (m[0][0]*x[0][1]+m[0][1]*x[1][1]) % 1000000007
  c = (m[1][0]*x[0][0]+m[1][1]*x[1][0]) % 1000000007
  d = (m[1][0]*x[1][0]+m[1][1]*x[1][1]) % 1000000007

  m[0][0] = a
  m[0][1] = b
  m[1][0] = c
  m[1][1] = d

  
print(fib(int(input())))