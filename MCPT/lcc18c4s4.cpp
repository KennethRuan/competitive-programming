#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 1e5+5;
int n,m, id[MAXN], sz[MAXN];
bool visited[MAXN];
vector<pii> g[MAXN];

struct edge{
    int a,b,c;
};
vector<edge> edges;

int compareEdges(edge l, edge r){
    return l.c < r.c;
}

int find(int root){
    int n = root;
    while(id[root] != root){
        root = id[root];
    }
    while (n != root){
        int p = id[n];
        id[n] = root;
        n = p;
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

int bfs(){
    memset(visited,false,sizeof(visited));
    deque<pii> q;
    q.push_back(make_pair(1,0));
    visited[1] = true;
    while (!q.empty()){
        int cur = q.front().first, mx = q.front().second;
        q.pop_front();
        if (cur == n){
            return mx;
        }
        for (pii i: g[cur]){
            if (!visited[i.first]){
                q.push_back(make_pair(i.first,max(i.second,mx)));
                visited[i.first] = true;
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        edge e; e.a = a; e.b = b; e.c = c;
        edges.push_back(e);
    }
    sort(edges.begin(),edges.end(), compareEdges);
    for (int i = 1; i <= n; i++){
        id[i] = i;
        sz[i] = 1;
    }

    for (edge i: edges){
        int a = i.a, b = i.b;
        int ra = find(a), rb = find(b);
        if (ra != rb){
            un(ra,rb);
            g[a].push_back(make_pair(b,i.c));
            g[b].push_back(make_pair(a,i.c));
        }
    }
    cout << bfs();
}