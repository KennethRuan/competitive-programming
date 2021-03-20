#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int mxN = 5e5+5;
int n, pno, pnt, mxCnt = 0, up[mxN], down[mxN];
vector<int> g[mxN];
bool visited[mxN];

void pdfs(int node, int cnt){
    cnt++;
    for (int i: g[node]){
        if (!visited[i]) {
            visited[i] = true;
            if (cnt >= mxCnt){
                mxCnt = cnt;
                pno = i;
            }
            pdfs(i,cnt);
        }
    }
}
void pdfs2(int node, int cnt){
    cnt++;
    for (int i: g[node]){
        if (!visited[i]) {
            visited[i] = true;
            up[i] = cnt;
            if (cnt >= mxCnt){
                mxCnt = cnt;
                pnt = i;
            }
            pdfs2(i,cnt);
        }
    }
}
void pdfs3(int node, int cnt){
    cnt++;
    for (int i: g[node]){
        if (!visited[i]) {
            visited[i] = true;
            down[i] = cnt;
            pdfs3(i,cnt);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
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
    visited[pnt] = true;
    pdfs3(pnt,0);

    for (int i = 0; i < n; i++){
        cout << max(down[i],up[i])+1 << "\n";
    }

}