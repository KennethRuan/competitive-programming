#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int mxN = 1e5+5;
int n, m, dp[mxN];
vector<int> g[mxN];

int dfs(int node){
    if (dp[node] != 0) return dp[node];
    for (int i:g[node]){
        dp[node] = max(dp[node],dfs(i)+1);
    }
    return dp[node];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp,0,sizeof(dp));
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans = max(ans,dfs(i));
    }
    cout << ans;
}