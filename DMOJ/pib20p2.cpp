#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
  ull t;
  cin >> t;
  ull ps = (t/5)*14;
  ull ans;
  for (int i = 14; i > 0; i--){
      if((ps+i)/2-(ps+i)/7 == t){
          ans = ps+i;
          break;
      }
  }
  cout << ans;
}