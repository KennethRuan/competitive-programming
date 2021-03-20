#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3005;

int bit[MAXN][MAXN], inp[MAXN][MAXN];

void update(int x, int y, int v)
{
  for (int i = x; i < MAXN; i += (i&-i)){
    for (int j = y; j < MAXN; j += (j&-j)){
      bit[i][j] = max(bit[i][j], v);
    }
  }
}

int query(int x, int y)
{
  int s = 0;
  for (int i = x; i > 0; i -= (i&-i)){
    for (int j = y; j > 0; j -= (j&-j)){
        s = max(bit[i][j], s);
    }
  }
  return s;
}

int main() {
  int n,k;
  long long ans = 0;
  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  cin >> n >> k;
  for (int i = 0; i < n; i++){
    for (int j = 0; j <= i; j++){
      cin >> inp[MAXN-n+i][MAXN-j-1]; //inp is stored as y then x?
    }
  }

  // cout << endl;
  // for (int i = MAXN-n; i < MAXN; i++){
  //   for (int j= MAXN-n;j < MAXN; j++){
  //     cout << inp[i][j] << " ";
  //   }
  //   cout << endl;
  // }

  for (int i = 0; i < n; i++){ //Iterates through each diagonal layer
    for (int j = 0; j <= i; j++){
      update(MAXN-j-1,MAXN-i+j-1,inp[MAXN-j-1][MAXN-i+j-1]);
    }
    int subt = i-k+2;
    for (int j = 0; j < subt; j++){
      // int temp = query(MAXN-i+k+j-2,MAXN-j-1);
      // cout << "At index: " << MAXN-i+k+j-2 <<","<< MAXN-j-1<<"\n";
      // cout << temp << "\n";
      ans += query(MAXN-i+k+j-2,MAXN-j-1);

    }
  }
  cout << ans;
}