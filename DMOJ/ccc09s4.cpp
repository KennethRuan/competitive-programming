#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int mn = 5e3+5;
vector<pii> graph[mn], pencils;
int n, t, k, sps[mn];

void dijk(int s){
    for (int i = 1; i <= n; i++){
        sps[i] = INT_MAX;
    }
    sps[s] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,s});
    while (!pq.empty()){
        int we = pq.top().first, node = pq.top().second;
        pq.pop();
        for (pii i:graph[node]){
            if (we + i.second < sps[i.first]){
                sps[i.first] = we + i.second;
                pq.push({we + i.second, i.first});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    for (int i = 0; i < t; i++){
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    cin >> k;
    for (int i = 0; i < k; i++){
        int z, p;
        cin >> z >> p;
        pencils.push_back({z,p});
    }
    int d;
    cin >> d;
    dijk(d);
    int ans = INT_MAX;
    for (pii p: pencils){
        ans = min(ans, sps[p.first] + p.second);
    }
    cout << ans;
}