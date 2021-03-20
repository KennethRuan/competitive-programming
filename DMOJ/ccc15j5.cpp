#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mn = 255;
int dp[mn][mn];

int solve(int n, int k){
    if (dp[n][k] != -1) return dp[n][k];
    if (n < 1) return dp[n][k] = 0;
    if (k > n) return dp[n][k] = 0;
    if (k == 1) return dp[n][k] = 1;
    int sum = 0;
    sum += solve(n-1, k-1);
    sum += solve(n-k, k);
    return dp[n][k] = sum;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp,-1,sizeof(dp));
    int n, k;
    cin >> n >> k;
    cout << solve(n,k);
}