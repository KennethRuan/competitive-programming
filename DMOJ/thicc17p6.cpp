#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int mxN = 2e5+5;
int n, t, pno, pnt, tot, mxCnt = 0, up[mxN], down[mxN];
vector<pii> g[mxN];
bool visited[mxN];

void pdfs(int node, int cnt){
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

void pdfs2(int node, int cnt){
    for (pii a: g[node]){
        int i = a.first, we = a.second;
        if (!visited[i]) {
            visited[i] = true;
            up[i] = cnt + we;
            if (cnt + we >= mxCnt){
                mxCnt = cnt + we;
                pnt = i;
            }
            pdfs2(i,cnt+we);
        }
    }
}

void pdfs3(int node, int cnt){
    for (pii a: g[node]){
        int i = a.first, we = a.second;
        if (!visited[i]) {
            visited[i] = true;
            down[i] = cnt + we;
            pdfs3(i,cnt+we);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    for (int i = 0; i < n-1; i++){
        int x, y, w;
        cin >> x >> y >> w;
        x--; y--;
        tot += w;
        g[x].push_back(make_pair(y,w));
        g[y].push_back(make_pair(x,w));
    }

    memset(visited,0,sizeof(visited));
    visited[0] = true;
    mxCnt = 0;
    pdfs(0,0);

    memset(visited,0,sizeof(visited));
    mxCnt = 0;
    visited[pno] = true;
    pdfs2(pno,0);

    memset(visited,0,sizeof(visited));
    mxCnt = 0;
    visited[pnt] = true;
    pdfs3(pnt,0);

//    cout << "Polar Nodes: " << pno+1 << " " << pnt+1 << "\n";
//    cout << "Longest Paths: \n";
//    for (int i = 0; i < n; i++){
//        cout << up[i] << " ";
//    }
//    cout << "\n";
//    for (int i = 0; i < n; i++){
//        cout << down[i] << " ";
//    }
//    cout << "\n";

    for (int i = 0; i < n; i++){
        if (g[i].size() == t){
            cout << i+1 << " " << min(2*tot-up[i],2*tot-down[i]) << "\n";
        }
    }

}