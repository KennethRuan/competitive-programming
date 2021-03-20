#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll mxn = 1e9;
const int mod = 998244353;
const int logn = 17;

ll n, x = 0, y = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        y |= x;
    }
    cout << min(mxn, y);
}