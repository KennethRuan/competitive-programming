#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mn = 1e6+5;
vector<vector<pii>> comp, graph;
vector<int> sps;
int n, m, bs = 1;
vector<vector<int>> grid;
pii dir[4] = {{-1,0},{1,0},{0,-1},{0,1}};
map<pii,int> vis;

void dijk(){
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,0});
    while (!pq.empty()){
        int we = pq.top().first, node = pq.top().second;
        pq.pop();
        for (pii i:graph[node]){
            if (we + i.first < sps[i.second]){
                sps[i.second] = we + i.first;
                pq.push({we + i.first, i.second});
            }
        }
    }
}

void recur(int i, int j, vector<pii> *pieces){
    pieces->push_back({i,j});
    for (pii a: dir){
        int ni = i + a.first, nj = j + a.second;
        if (0 <= ni && ni < n && 0 <= nj && nj < m){
            if (grid[ni][nj] == 1 && !vis[{ni,nj}]){
                vis[{ni,nj}] = bs;
                recur(ni, nj, pieces);
            }
        }
    }
}

int main(){
    cin >> n >> m;

    for (int i = 0; i < n; i++){
        vector<int> row;
        for (int j = 0; j < m; j++){
            char a;
            cin >> a;
            row.push_back((a == '#') ? 1:0);
        }
        grid.push_back(row);
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (grid[i][j] == 1 && !vis[{i,j}]){
                vector<pii> pieces;
                vis[{i,j}] = bs;
                recur(i,j,&pieces);
                bs++;
                comp.push_back(pieces);
            }
        }
    }

    vector<pii> d;
    for (int i = 0; i < comp.size()+1; i++){
        graph.push_back(d);
    }

    vector<int> row(m,1);
    grid.push_back(row);

    for (vector<pii> c : comp){
        for (pii p : c){
            int i = p.first, j = p.second;
            int r = vis[make_pair(i,j)];
            int nxt = i+1;
            if (!vis[{nxt,j}]) { //if the next part of the grid is not visited, it isn't apart of the same comp
                while (grid[nxt][j] == 0) { //checks while the next element isn't filled, accounts for the new row
                    nxt++;
                }
                graph[vis[{nxt,j}]].push_back({nxt - i -1, r}); // the floor layer is comp 0
            }
        }
    }
    
    for (int i = 0; i < comp.size()+1; i++){
        sps.push_back(mn);
    }
    sps[0] = 0;
    dijk();

    vector<vector<char>> ans(n, vector<char>(m, '.'));
    for (int x = 0; x < comp.size(); x++) {
        vector<pii> c = comp[x];
        for (pii p : c) {
            int i = p.first, j = p.second;
            ans[i+sps[x+1]][j] = '#';
        }
    }
    for (vector<char> v:ans){
        for(char c:v){
            cout << c;
        }
        cout << "\n";
    }
}