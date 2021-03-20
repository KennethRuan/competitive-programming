#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const ll mn = 2e5+5;
vector<pii> graph[mn];
ll sz[mn], n, ans = 0;
map<int,int> ma;
bool done[mn];

void getsz(ll node, ll prev){
    sz[node] = 1;
    for (pii i: graph[node]){
        int e = i.first;
        if (e != prev && !done[e]){
            getsz(e, node);
            sz[node] += sz[e];
        }
    }
}

ll getcentroid(ll node, ll prev, ll tot){
    for (pii i: graph[node]){
        int e = i.first;
        if (e != prev && !done[e] && sz[e]*2 > tot)
            return getcentroid(e, node, tot);
    }
    return node;
}

void dfs(int node, int prev, int w, vector<int>&path){
    ans += ma[1-w] + ma[-1-w];
    path.push_back(w);
    for (pii e: graph[node]){
        if (e.first != prev && !done[e.first])
            dfs(e.first, node, w + e.second, path);
    }
}

void solve(ll rt){
    getsz(rt,-1);
    rt = getcentroid(rt,-1,sz[rt]);
    done[rt] = true;
    ma.clear();
    ma[0] = 1;
    for (pii e: graph[rt]){
        int v = e.first, w = e.second;
        if (!done[v]){
            vector<int>path;
            dfs(v, rt, w, path);
            for (int x:path) ma[x]++;
        }
    }
    for (pii i:graph[rt]){
        if(!done[i.first]) solve(i.first);
    }
}


int main() {
    cin >> n ;
    for (ll i=0, a, b;i<n-1;i++){
        char c;
        cin >> a >> b >> c;
        int w = (c == 'r') ? 1:-1;
        a--, b--;
        graph[a].emplace_back(make_pair(b,w));
        graph[b].emplace_back(make_pair(a,w));
    }
    solve(0);
    cout << ans - n + 1 << '\n';
}