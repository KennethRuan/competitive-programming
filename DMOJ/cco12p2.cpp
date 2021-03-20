#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

int n, m, inf = 999999999;

void dijk(int sps[],int s, vector<pii> g[]){
    priority_queue<int,vector<int>,greater<int>> pq;
    bool inq[n+1];
    memset(inq,0,sizeof(inq));
    for (int i = 0; i < n+1; i++){
        sps[i] = inf;
    }
    sps[s] = 0;
    pq.push(s);
    while(!pq.empty()){
        int node = pq.top();
        int w = sps[node];
        inq[node] = false;
        pq.pop();
        for (pii i:g[node]){
            if (w + i.first < sps[i.second]) {
                sps[i.second] = w + i.first;
                if (!inq[i.second]) {
                    inq[i.second] = true;
                    pq.push(i.second);
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    int sps[n+1],sps2[n+1];
    int edges[m][3];
    vector<pii> g[n+1], g2[n+1];
    for (int i = 0; i < m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        edges[i][0] = a;
        edges[i][1] = b;
        edges[i][2] = w;
        g[a].push_back(make_pair(w,b));
        g2[b].push_back(make_pair(w,a));
    }
    dijk(sps,1,g);
    dijk(sps2,n,g2);

//    for (int i = 1; i < n+1; i++){
//        cout << sps[i] << endl;
//    }
    int best = inf;
    for (int i = 0; i < m; i++){
        int dist = sps[edges[i][0]] + edges[i][2] + sps2[edges[i][1]];
        if (dist > sps[n] && dist < best){
            best = dist;
        }
    }
    if (best == inf) cout << -1;
    else cout << best << "\n";
}