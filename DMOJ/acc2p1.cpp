#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

const ll MAXN = 9999999999999999;

int n,q;
ll dp[105][105][105];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    memset(dp,-1,sizeof(dp));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> dp[i][j][1];
            if (dp[i][j][1] == 0) dp[i][j][1] = MAXN;
            if (i == j) dp[i][j][1] = 0;
        }
    }

    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if (dp[i][k][1] + dp[k][j][1] < dp[i][j][1]) {
                    dp[i][j][1] = dp[i][k][1] + dp[k][j][1];
                }
            }
        }
    }

    for (int k = 2; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                for (int l = 1; l <= n; l++){
                    dp[i][j][k] = min((dp[i][j][k]==-1)?MAXN:dp[i][j][k],max(dp[i][l][k-1],dp[l][j][1]));
                }
            }
        }
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        int s,t,d;
        cin >> s >> t >> d;
        ll ans = dp[s][t][d];
        if (ans == MAXN) cout << 0 << "\n";
        else cout << ans << "\n";
    }

}