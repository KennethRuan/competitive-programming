from math import factorial as f
n,k = map(int,input().split())
print(f(n)**2//(f(k)*f(n-k)**2) if k <= n else 0)