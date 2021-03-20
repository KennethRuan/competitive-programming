#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mn = 5e3+5;
int n, idx = 1;;
int graph[16][16], dp[16][1 << 16];
pii coord[16];

int dist(pii p1, pii p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int dfs(int v, int node){
    if (dp[node][v] != INT_MAX){
        return dp[node][v];
    }
    int mn = INT_MAX;
    for (int i = 1; i < idx; i++){
        if (!(v & (1 << i))) {
            mn = min(mn, dist(coord[node], coord[i]) + dfs(v | (1 << i), i));
        }
    }
    if (mn == INT_MAX) return dp[node][v] = dist(coord[node], coord[0]);
    return dp[node][v] = mn;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(graph,-1,sizeof(graph));
    for (int i = 0; i < 16; i++){
        for (int j = 0; j < (1 << 16); j++){
            dp[i][j] = INT_MAX;
        }
    }
    cin >> n;
    char c;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
           cin >> c;
           if (c == 'P'){
               coord[idx] = {i,j};
               idx++;
           }
           if (c == 'H'){
               coord[0] = {i,j};
           }
        }
    }
    cout << dfs(0,0);
}