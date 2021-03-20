#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int mn = 3e5+5;
const int logN = 20;
int sn[mn], dist[mn], st[mn][logN], n;

int minimum(int u, int v){
    if (dist[u] < dist[v]){
        swap(u,v);
    }
    int diff = dist[u] - dist[v];
    for (int i = 0; i < logN; i++){
        if ((1<<i) & diff){
            u = st[u][i];
        }
    }
    if (u == v) return u;
    for (int i = logN-1; i >= 0; i--){
        if (st[u][i] != st[v][i]){
            u = st[u][i];
            v = st[v][i];
        }
    }
    return st[u][0];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        char op;
        cin >> op;
        if (op == 'a'){
            int v;
            cin >> v;
            int node = sn[v]; //stack that is copied

            sn[i] = i; //step refers back to new node
            dist[i] = dist[node] + 1;

            st[i][0] = node; //update sparse table or smth
            for (int j = 1; j < logN; j++){
                st[i][j] = st[st[i][j - 1]][j - 1];
            }
        }
        else if (op == 'b'){ //refers index at this step to par of node
            int v;
            cin >> v;
            int node = sn[v];
            sn[i] = st[node][0];
            cout << node << "\n";
        }
        else{
            int v, w;
            cin >> v >> w;
            sn[i] = sn[v];
            cout << dist[minimum(sn[v],sn[w])] << "\n";
        }
    }
}