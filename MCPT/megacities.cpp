#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 1e5+5;
int n,m, id[MAXN], sz[MAXN]; //cost stores current largest cost to add the city into the megacity

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
//    for (edge i: edges){
//        cout << i.a << " " << i.b << " " << i.c << "\n";
//    }
    for (int i = 1; i <= n; i++){
        id[i] = i;
        sz[i] = 1;
    }
    int nc = n;
    ll ans = 0, tot = 0;
    if (pow(nc,2) - (n+1) * nc + n == 0){
        ans = max(ans,tot);
    }
    for (edge i: edges){
        int a = i.a, b = i.b;
        int ra = find(a), rb = find(b);
        if (ra != rb){
            tot += i.c;
            nc--;
            un(ra,rb);
        }
        if (pow(nc,2) - (n+1) * nc + n == 0){
            ans = max(ans,tot);
        }
    }
    cout << ans;
}