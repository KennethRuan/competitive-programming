#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mxN = 1e5+5;
int n, m, pno, pnt, diam, l, mxCnt;
vector<pii> g[mxN];
vector<int> radii;
pii parent[mxN];
bool visited[mxN],vis[mxN];

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
        if (!vis[i]) {
            vis[i] = true;
            parent[i] = make_pair(node,we);
            if (cnt + we >= l){
                l = cnt + we;
                pnt = i;
            }
            pdfs2(i,cnt+we);
        }
    }
}

int radius(int node){
    pno = node, pnt = node, l = 0;
    mxCnt = 0;
    visited[node] = true;
    pdfs(node,0);

    mxCnt = 0;
    vis[pno] = true;
    pdfs2(pno,0);

    int i = pnt, r = 0, diff = abs(l-r);

    if (l > diam){
        diam = l;
    }
    while (i != pno){
        int p = parent[i].first, we = parent[i].second;
        l -= we;
        r += we;
        if (abs(l-r) < diff){
            diff = abs(l-r);
        }
        else{
            l += we;
            r -= we;
//            cout << i << " " << l << " " << r << "\n";
            break;
        }
        i = p;
    }
    return max(l,r);
}

int travelTime(int N, int M, int L, int A[], int B[], int T[]){
    n = N; m = M;
    memset(visited, false, sizeof(visited));
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < m; i++){
        int a = A[i],b = B[i], w = T[i];
        g[a].push_back(make_pair(b,w));
        g[b].push_back(make_pair(a,w));
    }

    int num = 0;

    for (int i = 0; i < n; i++){
        if (!vis[i]){
            num++;
            radii.push_back(radius(i));
        }
    }
    sort(radii.begin(),radii.end(),greater<int>());
//    for (int i: radii){
//        cout << i << " ";
//    }
    if (num == 1){
        return diam;
    }
    else if (num == 2){
        return max(diam,radii[0]+radii[1]+L);
    }
    else{
        return max(diam,max(radii[0]+radii[1]+L,radii[1]+radii[2]+L+L));
    }
}
int main(){
    int A[] = {0, 8, 2, 5, 5, 1, 1, 10};
    int B[] = {8, 2, 7, 11, 1, 3, 9, 6};
    int T[] = {4, 2, 4, 3, 7, 1, 5, 3};
    cout << travelTime(12,8,2,A,B,T);
}