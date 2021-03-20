#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mxn = 1e5+5;
const int mod = 1e9+7;
const int logn = 17;
int n, d, st[mxn][logn], cost[mxn], depth[mxn];
vector<pii> g[mxn];


void dfs(ll u, ll p){
    for (pii a:g[u]){
        ll v = a.first, c = a.second;
        if (v == p) continue;
        cost[v] = cost[u]+c;
        st[v][0] = u;
        depth[v] = depth[u]+1;
        dfs(v, u);
    }
}

void gen(){
    for (ll i = 1; i < logn; i++){
        for (ll node = 1; node <= n; node++) {
            st[node][i] = st[st[node][i - 1]][i - 1];
        }
    }
}

ll lca(ll u, ll v){
    if (depth[u] < depth[v]){
        swap(u,v);
    }
    ll diff = depth[u] - depth[v];
    for (ll i = 0; i < logn; i++) {
        if ((1 << i) & diff) {
            u = st[u][i];
        }
    }
    if (u == v) return u;
    for (ll i = logn-1; i >= 0; i--){
        if (st[u][i] != st[v][i]){
            u = st[u][i];
            v = st[v][i];
        }
    }
    return st[u][0];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(depth, 0, sizeof(depth));
    memset(cost, 0, sizeof(depth));
    memset(st, 0, sizeof(st));
    cin >> n >> d;
    for (ll i = 0; i < n-1; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }

    dfs(0, 0);
    gen();

    ll n1 = 0, n2 = 0, c1 = 0, c2 = 0, a = 0, b = 0, ic1 = 0, ic2 = 0, anc = 0, p1 = 0, p2 = 0, t1 = 0, t2 = 0;

    for (ll i = 0; i < d; i++){
        cin >> a >> b;
        a--;b--;

        //From node 1 ending at a
        anc = lca(n1, b);
        p1 = (cost[n1]-cost[anc]) + (cost[b]-cost[anc]);
        anc = lca(b, a);
        p2 = (cost[b]-cost[anc]) + (cost[a]-cost[anc]);
        ic1 = c1 + (p1 + p2);

        //From node 2 ending at a
        anc = lca(n2, b);
        p1 = (cost[n2] - cost[anc]) + (cost[b]-cost[anc]);
        anc = lca(b,a);
        p2 = (cost[b] - cost[anc]) + (cost[a]-cost[anc]);
        ic2 = c2 + (p1 + p2);

        //Cost of ending at a
        t1 = min(ic1,ic2);

        //From node 1 ending at b
        anc = lca(n1, a);
        p1 = (cost[n1] - cost[anc]) + (cost[a]-cost[anc]);
        anc = lca(b,a);
        p2 = (cost[a] - cost[anc]) + (cost[b]-cost[anc]);
        ic1 = c1 + (p1 + p2);

        //From node 2 ending at b
        anc = lca(n2, a);
        p1 = (cost[n2] - cost[anc]) + (cost[a]-cost[anc]);
        anc = lca(b,a);
        p2 = (cost[a] - cost[anc]) + (cost[b]-cost[anc]);
        ic2 = c2 + (p1 + p2);

        //Cost of ending at b
        t2 =  min(ic1, ic2);

        //Updating data
        c1 = t1;
        n1 = a;
        c2 = t2;
        n2 = b;
    }

    cout << min(c1,c2) << "\n";

//    for (int i = 0; i < n; i++){
//        cout << cost[i] << " ";
//    }
//    cout << "\n";
//
//    for (int i = logn-1; i >= 0; i--){
//        for (int j = 0; j < n; j++){
//            cout << st[j][i] << " ";
//        }
//        cout << "\n";
//    }
}