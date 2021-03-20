#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mn = 2e2+5;
int level[mn], opt[mn], cost[mn], s, t, n, m, idx = 0, ans = 0;

struct Edge{
    int u, v, cap, flow = 0;
    Edge(int u, int v, int cap) : u(u), v(v), cap(cap) {}
};
vector<Edge> edges;
vector<int> graph[mn];

bool bfs(){
    memset(level, -1, sizeof(level));
    deque<int> q;
    q.push_back(s);
    level[s] = 0;
    while (!q.empty()){
        int node = q.front();
        q.pop_front();
        for (int id: graph[node]){
            Edge e = edges[id];
            int cap = e.cap - e.flow;
            if (cap > 0 && level[e.v] == -1){
                level[e.v] = level[node] + 1;
                q.push_back(e.v);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int node, int flow){
    if (node == t) return flow;
    for(int& cid = opt[node]; cid < graph[node].size(); opt[node]++){
        int id = graph[node][cid];
        int v = edges[id].v;
        int cap = edges[id].cap - edges[id].flow;
        if (cap > 0 && level[v] == level[node] + 1){
            int bn = dfs(v, min(flow, cap));
            if (bn > 0){
                edges[id].flow += bn;
                edges[id ^ 1].flow -= bn;
                return bn;
            }
        }
    }
    return 0;
}

void solve(){
    while(bfs()) {
        memset(opt, 0, sizeof(opt));
        for (int f = dfs(s, INT_MAX); f != 0; f = dfs(s, INT_MAX)){
            ans += f;
        }
    }
}

void addEdge(int u, int v, int cap){
    edges.push_back(Edge(u,v,cap));
    edges.push_back(Edge(v,u,0));
    graph[u].push_back(idx);
    graph[v].push_back(idx+1);
    idx += 2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    s = 1; t = n;
    for (int i = 1; i < n; i++){
        cin >> cost[i];
        addEdge(i,i+100, cost[i]);
    }
    cost[n] = INT_MAX;

//    for (int i = 1; i <= n; i++){
//        cout << cost[i] << " ";
//    }
//    cout << "\n";

    cin >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        addEdge(a+100,b,INT_MAX);
    }
//    cout << "\n";
//    for (int i = 0; i < 4; i++){
//        cout << edges[i].u << " " << edges[i].v << " " << edges[i].flow << " " << edges[i].cap << "\n";
//    }

    solve();

//    for (int i = 1; i <= n; i++){
//        cout << level[i] << " ";
//    }
//    cout << "\n";
    cout << ans;
}