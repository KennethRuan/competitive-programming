//Headers
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int mxn = 3e7;

ll n, dp[mxn];

ll solve(int w){
    if (w < mxn) {
        if (dp[w])
            return dp[w];
    }
    if (w == 1)
        return 1;
    ll ans = 0;
    ll i = 2;
    while (i <= w){
        ll a = w/i;
        ll b = w/a;
        ans += (b-i+1) * solve(a);
        i = b+1;
    }
    if (w < mxn)
        dp[w] = ans;
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, 0, sizeof(dp));
    cin >> n;
    cout << solve(n);
}