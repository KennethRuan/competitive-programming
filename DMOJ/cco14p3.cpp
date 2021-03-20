#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll mn = 2e3+5;
const int mod = 1e9+7;

ll n, w, m;
ll dp[mn][mn][2], indeg[mn];
bool vis[mn][2];
vector<pii> g[mn];

void dfs(int node, int st){ //0 is civ, 1 is werewolf
    if (vis[node][st]) return;
    vis[node][st] = true;

    dp[node][0][st] = ((st == 0)? 1:0);
    dp[node][1][st] = st;

    for (pii e: g[node]){
        dfs(e.first, 0);
        dfs(e.first, 1);

        for (int i = w; i >= 0; i--){
            ll cnt = 0;
            for (int j = 0; j <= i; j++){
                if (st == 0) { //civ
                    cnt = (cnt + dp[e.first][i - j][0] * dp[node][j][0]) % mod;
                    cnt = (cnt + dp[e.first][i - j][1] * dp[node][j][0]) % mod;
                }
                else{ //were
                    if (e.second == 0) cnt = (cnt + dp[e.first][i - j][1] * dp[node][j][1]) % mod; //defended is were
                    if (e.second == 1) cnt = (cnt + dp[e.first][i - j][0] * dp[node][j][1]) % mod; //accused is civ
                }
            }
            dp[node][i][st] = cnt % mod;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> w >> m;
    memset(indeg, 0, sizeof(indeg));
    memset(vis, false, sizeof(vis));

    for (int i = 0; i < m; i++){
        char c; int a, b;
        cin >> c >> a >> b;
        g[a].push_back({b, (c == 'D')?0:1}); //0 is def, 1 is accused
        indeg[b]++;
    }
    for (int i = 1; i <= n; i++){
        if (indeg[i] == 0) g[0].push_back({i, 0});
    }
    dfs(0, 0);
    cout << dp[0][w][0] % mod;
}