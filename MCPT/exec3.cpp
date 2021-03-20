#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxn = 1e4+5;
const int mod = 1e6+7;
const int logn = 17;

ll dp[mxn][2], n, a[mxn]; //0 unrestricted, 1 restricted

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp,0,sizeof(dp));
    cin >> n;
    for (ll i = 0; i < n; i++){
        cin >> a[i];
    }
    ll mx = 0;
    for (ll i = 0; i < n; i++){
        for (ll j = n; j > 0; j--){
//            if (j > a[i]) {
//                dp[j][0] = (dp[j][0] * j + dp[j-1][0]) % mod; //pc
//            }
//            else {

//            if (j == mx-1)
//                dp[j][0] = (dp[j][0] * j + dp[j - 1][0] + (a[i]-1)) % mod;
//            else
                dp[j][0] = (dp[j][0] * j + dp[j - 1][0]) % mod; // un
//            }
        }
        dp[mx][0] = (dp[mx][0] + (a[i]-1)) % mod;
        mx = max(mx, a[i]);
//        cout << "ur: ";
//        for (ll j = 1; j < n+1; j++){
//            cout << dp[j][0] << " ";
//        }
//        cout << "r: ";
//        for (ll j = 1; j < n+1; j++){
//            cout << dp[j][1] << " ";
//        }
//        cout << "\n";
    }
    ll ans = 0;
    for (ll i = 1; i < n+1; i++){
        ans = (ans + dp[i][0]) % mod;
    }
    cout << (ans + 1) % mod << "\n";
}