#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mxN = 1e5+5;
int n, m, q, pno, pnt;
ll l, mxCnt;
vector<pii> g[mxN];
pii parent[mxN];
bool visited[mxN],vis[mxN];

void pdfs(int node, ll cnt){
    for (pii a: g[node]){
        int i = a.first, we = a.second;
        if (!visited[i]) {
            visited[i] = true;
            if (cnt + we >= mxCnt){
                mxCnt = cnt + we;
                pno = i;
            }
            pdfs(i,cnt+we);
        }
    }
}

void pdfs2(int node, ll cnt){
    for (pii a: g[node]){
        int i = a.first, we = a.second;
        if (!vis[i]) {
            vis[i] = true;
            if (cnt + we >= mxCnt){
                mxCnt = cnt + we;
            }
            pdfs2(i,cnt+we);
        }
    }
}

void pdfs3(int node, ll cnt){
    for (pii a: g[node]){
        int i = a.first, we = a.second;
        if (!vis[i]) {
            vis[i] = true;
            parent[i] = make_pair(node,we);
            if (cnt + we >= l){
                l = cnt + we;
                pnt = i;
            }
            pdfs3(i,cnt+we);
        }
    }
}

ll diameter(int node){
    pno = node;
    mxCnt = 0;
    visited[node] = true;
    pdfs(node,0);

    mxCnt = 0;
    vis[pno] = true;
    pdfs2(pno,0);
    return mxCnt;
}

ll radius(int node){
    pno = node, pnt = node, l = 0;

    mxCnt = 0;
    visited[node] = true;
    pdfs(node,0);

    mxCnt = 0;
    vis[pno] = true;
    pdfs3(pno,0);

    int i = pnt;
    ll r = 0, diff = abs(l-r);

    while (i != pno){
        int p = parent[i].first, we = parent[i].second;
        l -= we;
        r += we;
        i = p;
        if (abs(l-r) < diff){
            diff = abs(l-r);
        }
        else{
            l += we;
            r -= we;
            break;
        }
    }
    return max(l,r);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> q;
    memset(visited, false, sizeof(visited));
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        a--; b--;
        g[a].push_back(make_pair(b,w));
        g[b].push_back(make_pair(a,w));
    }
    if (q == 1){
        ll tot = -1;
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                tot += diameter(i) + 1;
            }
        }
        cout << tot;
    }
    else{
        ll mxRad = 0, cnt = 0;
        for (int i = 0; i < n; i++){
            if (!vis[i]){
                ll rad = radius(i);
                if (rad == mxRad){
                    cnt++;
                }
                else if (rad > mxRad){
                    mxRad = rad;
                    cnt = 1;
                }
            }
        }
        if (cnt > 1) cout << mxRad + 1;
        else cout << mxRad;
    }
}