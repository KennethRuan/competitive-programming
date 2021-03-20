#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int id[100005], sz[100005], steps[100005], visited[100005], n, m, q, idk = 1;
vector<int> g[100005];

int find(int root){
    if(id[root] == root){
        return root;
    }
    return id[root] = find(id[root]);
}

void un(int id1, int id2){
    int a = find(id1), b = find(id2);
    if (a != b) {
        if (sz[a] >= sz[b]) {
            sz[a] += sz[b];
            id[b] = a;
        } else {
            sz[b] += sz[a];
            id[a] = b;
        }
    }
}

int bfs(int s, int e){
    deque<pii> qu;
    int b = idk;
    qu.push_back({s,idk});
    qu.push_back({e,idk+1});
    steps[s] = 0; steps[e] = 0;
    visited[s] = idk; visited[e] = idk+1;
    idk += 2;
    while (!qu.empty()){
        int cur = qu.front().first, idx = qu.front().second;
        qu.pop_front();
//        cout << cur << " " << idx;
        for (int i:g[cur]){
            if (visited[i] < b){
                qu.push_back({i,idx});
                visited[i] = idx;
                steps[i] = steps[cur]+1;
            }
            else if(visited[i] != idx){
                return steps[i] + steps[cur]+1;
            }
        }
    }
    return 42069;
}


int main() {
    for (int i = 0; i < 100005; i++){
        id[i] = i;
    }
    memset(sz,1,sizeof(sz));
    memset(steps,-1,sizeof(steps));
    memset(visited,-1,sizeof(visited));
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        un(a, b);
    }

    for (int i = 0; i < q; i++){
        int a,b;
        cin >> a >> b;
        if (a == b){
            cout << 0 << "\n";
        }
        else if(find(a) == find(b)){
            cout << bfs(a,b) << "\n";
        }
        else cout << -1 << "\n";
    }

}