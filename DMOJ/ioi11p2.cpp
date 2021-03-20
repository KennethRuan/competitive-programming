#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll mn = 2e5+5;
vector<pii> graph[mn];
int sz[mn], n, k, ans = 9999999;
map<int,int> ma;
bool done[mn];

void getsz(ll node, ll prev){
    sz[node] = 1;
    for (pii i: graph[node]){
        int e = i.first;
        if (e != prev && !done[e]){
            getsz(e, node);
            sz[node] += sz[e];
    }
    }
}

ll getcentroid(ll node, ll prev, ll tot){
    for (pii i: graph[node]){
        int e = i.first;
        if (e != prev && !done[e] && sz[e]*2 > tot)
            return getcentroid(e, node, tot);
    }
    return node;
}

void dfs(int node, int prev, int w, int m, vector<pii>&path){
    if (ma[k - w] != 0) {
        ans = min(ans, m + ma[k - w]);
    }
    path.push_back(make_pair(w,m));
    for (pii e: graph[node]){
        if (e.first != prev && !done[e.first])
            dfs(e.first, node, w + e.second, m+1, path);
    }
}

void solve(ll rt){
    getsz(rt,-1);
    rt = getcentroid(rt,-1,sz[rt]);
    done[rt] = true;
    ma.clear(); // if ma[x] = 0, val is considered not found, -2 from ans at the end
    ma[0] = 1;

    for (pii e: graph[rt]){
        int v = e.first, w = e.second;
        if (!done[v]){
            vector<pii>path;
            dfs(v, rt, w, 2, path);
            for (pii x:path){
                if (ma[x.first] != 0) {
                    ma[x.first] = min(ma[x.first], x.second);
                }
                else{
                    ma[x.first] = x.second;
                }
            }
        }
    }
    for (pii i:graph[rt]){
        if(!done[i.first]) solve(i.first);
    }
}

int best_path(int N, int K, int H[][2], int L[]){
    n = N;
    k = K;
    for (int i=0, a, b, w; i<n-1; i++){
        a = H[i][0], b = H[i][1], w = L[i];
        graph[a].emplace_back(make_pair(b,w));
        graph[b].emplace_back(make_pair(a,w));
    }
    solve(0);
    return (ans != 9999999) ? ans - 2:-1;
}

int main(){
    int H[10][2] = {{0,1},{0,2},{2,3},{3,4},{4,5},{0,6},{6,7},{6,8},{8,9},{8,10}};
    int L[10] = {3,4,5,4,6,3,2,5,6,7};
    cout << best_path(11,12,H,L);
}