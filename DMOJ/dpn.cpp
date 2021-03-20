#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mxN = 405;
int n, slimes[mxN];
ll dp[mxN][mxN], psa[mxN];

ll solve(int l, int r){
    if (dp[l][r] != LONG_LONG_MAX){
        return dp[l][r];
    }
    for (int i = l; i < r; i++){
        dp[l][r] = min(dp[l][r], solve(l,i) + solve(i+1,r) + psa[r+1]-psa[l]);
    }
    return dp[l][r];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dp[i][j] = LONG_LONG_MAX;
            if (i == j){
                dp[i][j] = 0;
            }
        }
    }
    psa[0] = 0;
    for (int i = 0; i < n; i++){
        cin >> slimes[i];
        psa[i+1] = psa[i] + slimes[i];
    }
    cout << solve(0,n-1) << "\n";
}