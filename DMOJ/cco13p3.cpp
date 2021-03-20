#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const int mxN = 4e5+5;
int n;
ll dia, ans, dias[mxN], cnt[mxN];
vector<int> g[mxN];
void dfs(int node, int p){
    dias[node] = 0; cnt[node] = 1;
    for (int i: g[node]){
        if (i != p){
            dfs(i,node);

            if (dias[i] + dias[node] + 1 > dia){
                dia = dias[i] + dias[node] + 1;
                ans = cnt[i] * cnt[node];
            }
            else if (dias[i] + dias[node] + 1 == dia){
                ans += cnt[i] * cnt[node];
            }

            if (dias[i] + 1 > dias[node]){
                dias[node] = dias[i] + 1;
                cnt[node] = cnt[i];
            }
            else if (dias[i] + 1 == dias[node]){
                cnt[node] += cnt[i];
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int a,b;
    for (int i = 0; i < n-1; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1);
    cout << dia+1 << " " << ans;
}