#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int MAXN = 1e5+5;
int n,m, id[MAXN], sz[MAXN], visited[MAXN], bs = 1;
vector<int> g[MAXN], cycles;

int bfs(int s, int e){
    deque<pii> q;
    q.push_back(make_pair(s,1));
    visited[s] = bs;
    while (!q.empty()){
        int cur = q.front().first, steps = q.front().second;
        q.pop_front();
        if (cur == e){
            return steps;
        }
//        cout << "Neighbours: ";
        for (int i: g[cur]){
//            cout << i << " ";
            if (visited[i] < bs){
                q.push_back(make_pair(i,steps+1));
                visited[i] = bs;
            }
        }
//        cout << "\n";
    }
    return -1;
}


int find(int root){
    int n = root;
    while(id[root] != root){
        root = id[root];
    }
    while (n != root){
        int p = id[n];
        id[n] = root;
        n = p;
    }
    return root;
}

void un(int a, int b){ //has to be the roots, use find
    if (sz[a] > sz[b]){
        id[b] = a;
        sz[a] += sz[b];
    }
    else{
        id[a] = b;
        sz[b] += sz[a];
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    memset(visited,0,sizeof(visited));
    for (int i = 1; i <= n; i++){
        id[i] = i;
        sz[i] = 1;
    }
    int len = 0;
    int nc = 0; //number of components, expected number of cycles left
    int tot = 1;
    bool as = true;

    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        int ra = find(a), rb = find(b);
        if (ra == rb){ //if it forms a cycle
            int cur_len = bfs(a,b); //dfs or bfs to find the length
            bs++;
            if (as){
                len = cur_len;
                cycles.push_back(len);
                as = false;
            }
            if (cur_len != len){
                cout << "baf";
                return 0;
            }
            if (nc == 0){
                nc = tot;
                as = true;
            }
            nc--;
        }
        else{
            un(ra,rb);
            tot++; //a new component was added
        }
        g[a].push_back(b); // maybe make bi-directional idk
        g[b].push_back(a);
    }

    if (!as){ //didn't end w complete set of cycles
        cout << "baf";
    }
    else{
        for (int i: cycles){
            cout << i << "\n";
        }
    }
}