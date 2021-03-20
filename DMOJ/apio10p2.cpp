#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mxN = 1e5+5;
int n, k, dia, dia2, pa[mxN], pno, pnt;
vector<int> g[mxN];
map<pii,int> g2;

void dfs(int u, int p, int cnt, int &pn){
    cnt += 1;
    for (int v: g[u]){
        if (v == p) continue;
        pa[v] = u;
        dfs(v,u,cnt,pn);
    }
    if (cnt > dia){
        dia = cnt;
        pn = u;
    }
}

int dfs2(int u, int p){
    int h1 = 0, h2 = 0;
    for (int v: g[u]){
        if (v == p) continue;
        int cur = dfs2(v,u) + g2[make_pair(u,v)];
        if (cur > h1){
            h2 = h1;
            h1 = cur;
        }
        else if (cur > h2){
            h2 = cur;
        }
    }
    dia2 = max(dia2,h1+h2);
    return h1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int a,b;
    for (int i = 0; i < n-1; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1,-1,pno);
    dia = 0;
    dfs(pno,-1,-1,pnt);

    if (k == 1){
        cout << 2*(n-1) - dia + 1;
    }
    else{
        for (int i = 0; i < n+1; i++){
            for (int j = 0; j < g[i].size(); j++){
                g2.insert(make_pair(make_pair(i,g[i].at(j)),1));
                g2.insert(make_pair(make_pair(g[i].at(j),i),1));
            }
        }
        while (pnt != pno){
//            cout << pno << " " << pnt << " " << pa[pnt] << "\n";
            g2[make_pair(pnt,pa[pnt])] = -1;
            g2[make_pair(pa[pnt],pnt)] = -1;
            pnt = pa[pnt];
        }
        dfs2(1,-1);
//        cout << dia << " " << dia2 << "\n";
        cout << 2*(n-1) - dia - dia2 + 2;
    }
}