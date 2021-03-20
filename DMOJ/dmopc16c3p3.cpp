#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

const int mn = 5e3+5;

ll dp[mn], n, m;
pii ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    ans = {0,m};
    dp[0] = m;
    for (ll i = 1; i <= n; i++){

        ll a,b;
        cin >> a >> b;

        for (ll j = i; j > 0; j--){
            if (dp[j-1] - a + b > dp[j] && dp[j-1] - a >= 0){
                dp[j] = dp[j-1] - a + b;
                if (j > ans.first){
                    ans = {j, dp[j]};
                }
                else if (j == ans.first){
                    ans = {j, max(ans.second,dp[j])};
                }
                
            }

        }
    }
//    for (ll i = n; i >= 0; i--){
//            cout << dp[i] << " ";
//    }

    cout << ans.first << " " << ans.second;
}