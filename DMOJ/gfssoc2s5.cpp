#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 5e5+5;
int n,m,id = 1,ids[MAXN],low[MAXN],val[MAXN],sval[MAXN],dp[MAXN][2], mod = 1000000007; //each nodes id, low-link, value, total val of scc
ll cnt[MAXN][2];
bool instk[MAXN];
stack<int> stk;
vector<int> graph[MAXN],g[MAXN];

void tarjans(int node){
    stk.push(node);
    instk[node] = true;
    ids[node] = low[node] = id++;
    for (int i:graph[node]){
        if (!ids[i]) tarjans(i);
        if (instk[i]) low[node] = min(low[node], low[i]);
    }
    if (ids[node] == low[node]){
        while (!stk.empty()){
            int cur = stk.top(); stk.pop();
            instk[cur] = false;
            low[cur] = ids[node];
            if (node == cur) break;
        }
    }
}

int dfs(int node, int take) {
    if (dp[node][take] != -1) return dp[node][take];
    int ans = 0;
    for (int i:g[node]){
        if (take){
            int mx = dfs(i,0) + sval[node];
            if (mx > ans){
                ans = mx;
                cnt[node][take] = cnt[i][0] % mod;
            }
            else if (mx == ans){
                cnt[node][take] = (cnt[node][take]%mod + cnt[i][0]%mod) % mod;
            }
        }
        int mx = dfs(i, 1);
        if (mx > ans){
            ans = mx;
            cnt[node][take] = cnt[i][1] % mod;
        }
        else if (mx == ans){
            cnt[node][take] = (cnt[node][take]%mod + cnt[i][1]%mod) % mod;
        }
    }
    return dp[node][take] = ans;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){ //1-indexed
        cin >> val[i];
    }
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= n; i++){
        if (!ids[i])
            tarjans(i);
    }
    for (int i = 1; i <= n; i++){
        sval[low[i]] += val[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j:graph[i]){
            if (low[i] != low[j]){
                g[low[i]].push_back(low[j]);
            }
        }
    }
    memset(dp,-1,sizeof(dp));
    int f = low[n];
    dp[f][0] = 0;
    dp[f][1] = sval[f];
    cnt[f][0] = cnt[f][1] = 1;

    dfs(1,1);

    cout << dp[1][1] << " " << cnt[1][1] % mod;
}