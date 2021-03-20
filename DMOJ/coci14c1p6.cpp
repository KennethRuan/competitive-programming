#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const ll mn = 5e5+5;

ll n, m, pno, pnt, tot = 0, diam = 0, s = 0, up[mn], down[mn];
pii dist[mn];
bool inc[mn];
vector<pii> g[mn], graph[mn];
set<ll> kamp;

bool dfs(ll node, ll p, ll c){ //start from a random kamp, constructs new tree
    inc[node] = ((kamp.find(node) != kamp.end()));
    for (pii e: g[node]){
        ll i = e.first, w = e.second;
        if (i == p) continue;
        if (dfs(i, node,w)){
            inc[node] = true;
        }
    }
    if (inc[node]){
        if (p != -1){
            graph[p].push_back({node,c});
            graph[node].push_back({p,c});
        }
        tot += c;
    }
    return inc[node];
}

void dfs2(ll node, ll p, ll c, ll ln){ //gets distances for all of the nodes to the nearest kamp tree node
    if (inc[node]){ c = 0; ln = node;}
    dist[node] = {c,ln};

    for (pii e: g[node]) {
        ll i = e.first, w = e.second;
        if (i == p) continue;
        dfs2(i, node, c + w, ln);
    }
}

void pdfs(ll node, ll p, ll cnt){
    if (cnt > diam){
        diam = cnt;
        pno = node;
    }
    for (pii e: graph[node]){
        ll i = e.first, w = e.second;
        if (i == p) continue;
        pdfs(i, node, cnt + w);
    }
}

void pdfs2(ll node, ll p, ll cnt){
    if (cnt > diam){
        diam = cnt;
        pnt = node;
    }
    up[node] = cnt;
    for (pii e: graph[node]){
        ll i = e.first, w = e.second;
        if (i == p) continue;
        pdfs2(i, node, cnt + w);
    }
}

void pdfs3(ll node, ll p, ll cnt){
    down[node] = cnt;
    for (pii e: graph[node]){
        ll i = e.first, w = e.second;
        if (i == p) continue;
        pdfs3(i, node, cnt + w);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (ll i = 0; i < n-1; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    for (ll i = 0; i < m; i++){
        ll a;
        cin >> a;
        kamp.insert(a);
        s = a;
    }

    dfs(s, -1, 0);
    dfs2(s, -1, 0, s);
    pdfs(s, -1, 0);
    diam = 0;
    pdfs2(pno, -1, 0);
    diam = 0;
    pdfs3(pnt, -1, 0);

//    cout << tot << "\n";
//    for (ll i = 1; i <= n; i++){
//        for (ll j = 0; j < graph[i].size(); j++){
//            cout << graph[i][j].first << " " << graph[i][j].second << "\n";
//        }
//        cout <<"\n";
//    }
//
//    for (ll i = 1; i <= n; i++){
//        cout << up[i] << " ";
//    }
//    cout << "\n";
//    for (ll i = 1; i <= n; i++){
//        cout << down[i] << " ";
//    }
//    cout << "\n";

    for (ll i = 1; i <= n; i++){
        ll a = dist[i].first, b = dist[i].second;
        cout << 2*tot + a - max(up[b], down[b]) << "\n";
    }
}