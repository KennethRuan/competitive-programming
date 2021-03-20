#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int mxN = 1e5+5;
int n, k, dp[mxN], st[mxN];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        cin >> st[i];
    }
    for (int i = 1; i < n; i++){
        dp[i] = 1e9;
    }
    dp[0] = 0;
    for (int i = 0; i < n; i++){
        for (int j = 1; j < min(i,k)+1; j++){
            dp[i] = min(dp[i], dp[i-j] + abs(st[i]-st[i-j]));
        }
    }
    cout << dp[n-1] << "\n";
}