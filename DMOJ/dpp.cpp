#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mxN = 1e5+5;
int mod = 1e9+7, n;
ll dp[mxN][2];
vector<int> g[mxN];

ll dfs(int node, int bw, int p){  //b = 0, w = 1
    if (dp[node][bw] != -1) return dp[node][bw];
    ll sum = 1;
    if (bw == 0){
        for (int i: g[node]) {
            if (i != p) {
                sum = (sum*dfs(i, 1, node)) % mod;
            }
        }
    }
    else {
        for (int i: g[node]) {
            if (i != p) {
                sum = (sum*(dfs(i, 0, node) % mod + dfs(i, 1, node) % mod)) % mod;
            }
        }
    }
    return dp[node][bw] = sum;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; i++){
        int x,y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(dp,-1,sizeof(dp));
    cout << (dfs(0, 0, -1) % mod + dfs(0, 1, -1) % mod) %mod;
}