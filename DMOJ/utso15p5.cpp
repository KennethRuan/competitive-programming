#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mn = 5e4+5;
const int logN = 17;

int n, m, depth[mn], id[mn], sz[mn], st[mn][logN], cost[mn][logN];
int ans = 0;
vector<pii> g[mn];

struct edge{
    int a,b,c;
};
vector<edge> edges;
vector<edge> unused;

int compareEdges(edge l, edge r){
    return l.c < r.c;
}

int find(int root){
    int ne = root;
    while(id[root] != root){
        root = id[root];
    }
    while (ne != root){
        int p = id[ne];
        id[ne] = root;
        ne = p;
    }
    return root;
}

void un(int a, int b){ //has to be the roots, use find
    if (sz[a] > sz[b]){
        id[b] = a;
        sz[a] += sz[b];
    }
    else{
        id[a] = b;
        sz[b] += sz[a];
    }
}

void dfs(int node, int p, int c){
    st[node][0] = p;
    cost[node][0] = c;
    depth[node] = depth[p] + 1;

    for (pii e: g[node]){
        int i = e.first;
        if (i == p) continue;
        dfs(i, node, e.second);
    }
}

void gen(){
    for (int i = 1; i < logN; i++){
        for (int node = 1; node <= n; node++) {
            st[node][i] = st[st[node][i - 1]][i - 1];
            cost[node][i] = max(cost[node][i - 1], cost[st[node][i - 1]][i - 1]);
        }
    }
}

int minimum(int u, int v){
    if (depth[u] < depth[v]){
        swap(u,v);
    }
    int diff = depth[u] - depth[v];
    for (int i = 0; i < logN; i++){
        if ((1<<i) & diff){
            int a = (1<<i) && diff;
            u = st[u][i];
        }
    }
    if (u == v) return u;
    for (int i = logN-1; i >= 0; i--){
        if (st[u][i] != st[v][i]){
            u = st[u][i];
            v = st[v][i];
        }
    }
    return st[u][0];
}

int maxCost(int u, int v){
    if (depth[u] < depth[v]){
        swap(u,v);
    }
    int exp = -1;
    int diff = depth[u] - depth[v];
    for (int i = 0; i < logN; i++){
        if ((1<<i) & diff){
            exp = max(exp,cost[u][i]);
            u = st[u][i];
        }
    }
    return exp;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        edge e;
        cin >> e.a >> e.b >> e.c;
        edges.push_back(e);
    }
    sort(edges.begin(),edges.end(),compareEdges);
    for (int i = 1; i <= n; i++) {
        id[i] = i;
        sz[i] = 1;
    }
    int nc = n;
    for (int i = 0; i < edges.size(); i++){
        int a = edges[i].a, b = edges[i].b, c = edges[i].c;
        int ra = find(a), rb = find(b);
        if (ra != rb){
            g[a].push_back({b,c});
            g[b].push_back({a,c});
            ans += c;
            un(ra,rb);
            nc--;
        }
        else{
            unused.push_back(edges[i]);
        }
    }

    if (nc != 1){
        cout << -1;
        return 0;
    }

    dfs(1,0,0);
    gen();

    int best = INT_MAX; //stores smallest diff after changing a piece
    for (int i = 0; i < unused.size(); i++){
        int a = unused[i].a, b = unused[i].b, c = unused[i].c;
        int lca = minimum(a,b);
        int exp = max(maxCost(a,lca),maxCost(b,lca));

        if (c - exp > 0) best = min(best, c-exp);
    }


//    for (int j = 0; j < ceil(log2(n)); j++){
//        for (int i = 1; i <= n; i++){
//            cout << st[i][j] << " ";
//        }
//        cout << "\n";
//    }

//    for (int j = 0; j < ceil(log2(n)); j++){
//        for (int i = 1; i <= n; i++){
//            cout << cost[i][j] << " ";
//        }
//        cout << "\n";
//    }

    cout << ((best == INT_MAX) ? -1:(ans+best));
}