#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mn = 5e3+5;
int n, m, q, id = 1,ids[mn],low[mn], sval[mn], dist[mn][mn]; //each nodes id, low-link, value, total val of scc

bool instk[mn], vis[mn], matchup[mn][mn];
stack<int> stk;
vector<int> graph[mn],g[mn];

void tarjans(int node){
    stk.push(node);
    instk[node] = true;
    ids[node] = low[node] = id++;
    for (int i:graph[node]){
        if (!ids[i]) tarjans(i);
        if (instk[i]) low[node] = min(low[node], low[i]);
    }
    if (ids[node] == low[node]){
        while (!stk.empty()){
            int cur = stk.top(); stk.pop();
            instk[cur] = false;
            low[cur] = ids[node];
            if (node == cur) break;
        }
    }
}

void dfs(int node, int start, int steps){
    for (int i:g[node]){
        if (dist[start][i] < dist[start][node] + sval[node]){
            dist[start][i] = dist[start][node] + sval[node];
            dfs(i, start, steps+sval[node]);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dist, -1, sizeof(dist));
    memset(vis, false, sizeof(vis));
    memset(matchup, false, sizeof(matchup));
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= n; i++){
        if (!ids[i])
            tarjans(i);
    }
    for (int i = 1; i <= n; i++){
        sval[low[i]]++;
        for (int j:graph[i]){
            if (low[i] != low[j]){
                g[low[i]].push_back(low[j]);
            }
        }
    }

//    for (int i = 1; i < id; i++){
//        cout << indeg[i] << " ";
//    }
//    cout << "\n";

    for (int i = 1; i < id; i++){
        if (!vis[low[i]])
            dfs(low[i], low[i], 0);
    }

//    for (int i = 1; i < id; i++){
//        cout << dist[i] << " ";
//    }
//    for (int i = 1; i < id; i++){
//        cout << sval[i] << " ";
//    }
//    cout << "\n";
//    for (int i = 1; i < id; i++){
//        for (int j = 1; j < id; j++){
//            cout << matchup[i][j] << " ";
//        }
//        cout << "\n";
//    }

    for (int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        int aa = low[a], bb = low[b];
        if (aa == bb) cout << "Indeterminate\n";
        else {
            if (dist[aa][bb] >= 0) cout << a << " " << dist[aa][bb] - sval[aa] + 1 << "\n";
            else if (dist[bb][aa] >= 0) cout << b << " " << dist[bb][aa] - sval[bb] + 1 << "\n";
            else cout << "Indeterminate\n";
        }
    }
//    for (int i = 1; i < id; i++){
//        for (int j = 1; j < id; j++){
//            cout << dist[i][j] << " ";
//        }
//        cout << "\n";
//    }
}