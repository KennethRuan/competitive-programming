#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e3+5;

ll n,r,id = 1, ids[MAXN], low[MAXN], comp[MAXN], cnt[MAXN], nc = 0, ans = 0;

bool instk[MAXN];
stack<ll> stk;
vector<ll> g[MAXN];

void tarjans(ll node, ll prev){
    stk.push(node);
    instk[node] = true;
    ids[node] = low[node] = id++;
    for (ll i:g[node]){
        if (i == prev) continue;
        if (!ids[i]) tarjans(i, node);
        if (instk[i]) low[node] = min(low[node], low[i]);
    }
    if (ids[node] == low[node]){
        while (!stk.empty()){
            ll cur = stk.top(); stk.pop();
            instk[cur] = false;
            low[cur] = low[node];
            comp[cur] = nc;
            if (node == cur) break;
        }
        nc++;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(cnt,0, sizeof(cnt));
    cin >> n >> r;
    for (int i = 0; i < r; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for (ll i = 1; i <= n; i++){
        if (!ids[i])
            tarjans(i, -1);
    }

    for (int i = 1; i <= n; i++){
        for (int j:g[i]){
            if (comp[i] != comp[j]){
                cnt[comp[i]]++;
            }
        }
    }

    for (int i = 0; i < nc; i++){
        if (cnt[i] < 2){
            ans += 2 - cnt[i];
        }
    }
    if (nc == 1) cout << 0;
    else cout << (ans + 1) / 2;
}