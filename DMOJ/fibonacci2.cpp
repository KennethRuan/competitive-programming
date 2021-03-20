#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

void mult(ull m[2][2], ull x[2][2]){
  ull a = (m[0][0]*x[0][0]% 1000000007 + m[0][1]*x[1][0] % 1000000007) % 1000000007;
  ull b = (m[0][0]*x[0][1] % 1000000007 + m[0][1]*x[1][1] % 1000000007) % 1000000007;
  ull c = (m[1][0]*x[0][0] % 1000000007 + m[1][1]*x[1][0] % 1000000007) % 1000000007;
  ull d = (m[1][0]*x[1][0] % 1000000007 + m[1][1]*x[1][1] % 1000000007) % 1000000007;

  m[0][0] = a;
  m[0][1] = b;
  m[1][0] = c;
  m[1][1] = d;
}

void power(ull m[2][2], ull p){
  if (p == 0 || p == 1)
    return;
  ull f[2][2] = {{1,1},
       {1,0}};
  power(m,p/2);
  mult(m,m);
  if (p%2 == 1)
    mult(m,f);
}

ull fib(ull n){
  ull m[2][2] = {{1,1},
       {1,0}};
  power(m,n-1);
  return m[0][0] % 1000000007;
}

int main() {
  ull n = 0;
  int ch;
  while ((ch = getchar_unlocked()) != '\n'){
    n = (n*10 + ch - '0') % 2000000016;
  }
  cout << fib(n);
}