#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxn = 2e3+5;
const int mod = 998244353;
const int logn = 17;

ll dp[mxn][mxn], n, a[mxn];

ll m(ll x){
    ll q = x / mod;
    ll r = x - (q*mod);
    while (r < 0)
        r += mod;
    return r;
}

ll solve(ll n, ll k){
    if (dp[n][k] != -1)
        return dp[n][k];
    if (n == 0)
        return m(a[0]);
    if (k == 1)
        return dp[n][k] = m(solve(n-1, k) + m(a[n]));
    if (n+1 == k)
        return dp[n][k] = m(solve(n-1,k-1) * a[n]);
    return dp[n][k] = m(solve(n - 1, k) + m(solve(n - 1, k - 1) * a[n]));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
        cout << solve(n-1, i) << " ";
}