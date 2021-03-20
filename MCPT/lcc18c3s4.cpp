#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mxN = 2e5+5;
int n, r, m;
vector<int> g[mxN];
vector<int> trees;

int dfs(int node, int p){
    int sz = 1;
    for (int i: g[node]){
        if (i != p) sz += dfs(i, node);
    }
    trees.push_back(sz);
    return sz;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> r >> m;
    int a,b;
    for (int i = 0; i < n-1; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(r,-1);
    sort(trees.begin(),trees.end());
    cout << trees.at(m-1);
}