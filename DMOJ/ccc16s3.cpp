#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mn = 1e6+5;

int n, m, pno, nc = 0, diam = 0, s = 0;
vector<int> g[mn], graph[mn];
set<int> pho;

bool dfs(int node, int p){ //start from a random pho shop
    bool inc = (pho.find(node) != pho.end());
    for (int i: g[node]){
        if (i == p) continue;
        if (dfs(i, node)){
            inc = true;
        }
    }
    if (inc){
        if (p != -1){
            graph[p].push_back(node);
            graph[node].push_back(p);
        }
        nc++;
    }
    return inc;
}

void pdfs(int node, int p, int cnt){
    if (cnt > diam){
        diam = cnt;
        pno = node;
    }
    for (int i: graph[node]){
        if (i == p) continue;
        pdfs(i, node, cnt + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a;
        cin >> a;
        pho.insert(a);
        s = a;
    }
    for (int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(s, -1);
    pdfs(s, -1, 0);
    pdfs(pno, -1, 0);

    cout << (nc-1)*2 - diam;
}