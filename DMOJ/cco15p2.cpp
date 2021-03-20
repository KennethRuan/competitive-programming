#include <bits/stdc++.h>
using namespace std;

int mx = 0;
int graph[18][18];
int dp[18][1<<18];
int n,m;

int dfs(int v, int node){
//    cout << bitset<18>(v) << " " << node << "\n";
    if (node == n-1){
        return 0;
    }
    if (dp[node][v]){
        return dp[node][v];
    }
    int mx = -INT_MAX;
    for (int i = 0; i < 18; i++){
        if (!(v & (1 << i)) && graph[node][i] != -1) {
            mx = max(mx, graph[node][i] + dfs(v | (1 << i), i));
        }
    }
    return dp[node][v] = mx;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    memset(graph,-1,sizeof(graph));
    for (int i = 0; i < m; i++){
        int a,b,w;
        cin >> a >> b >> w;
        graph[a][b] = w;
    }
    cout << dfs(1,0);
    return 0;
}