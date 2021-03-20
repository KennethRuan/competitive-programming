//Headers
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const int mxn = 2e5+5;
const int mod = 1e9+7;
const ll LLM = 9999999999;


ll n, w, d, t[mxn], sps[mxn], cost[mxn], ind[mxn];
vector<ll> wa[mxn];
map<ll, ll> ma;

void dijk(int s){
    for (int i = 0; i < n; i++){
        sps[i] = 9999999999;
    }
    sps[n] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0,s});
    while (!pq.empty()){
        ll c = pq.top().first;
        ll u = pq.top().second;
        pq.pop();

        for (ll v : wa[u]){
            if (c + 1 < sps[v]){
                sps[v] = c+1;
                pq.push({c+1, v});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> w >> d;
    for (int i = 0; i < w; i++){
        ll a,b;
        cin >> a >> b;
        wa[b].push_back(a);
    }
    for (int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        t[x] = i-1;
        ind[i] = x;
    }
    dijk(n);
    for (int i = 1; i <= n; i++){
        cost[i] = t[i]+sps[i];
        ma[cost[i]]++;
    }
    for (int i = 0; i < d; i++){
        ll a, b;
        cin >> a >> b;
        swap(t[ind[a]],t[ind[b]]);
        swap(ind[a], ind[b]);

        ll nca = sps[ind[a]] + t[ind[a]];
        ll ncb = sps[ind[b]] + t[ind[b]];

        ma[nca]++; ma[ncb]++;
        ma[cost[ind[a]]]--; ma[cost[ind[b]]]--;

        if (ma[cost[ind[a]]] == 0)
            ma.erase(cost[ind[a]]);
        if (ma[cost[ind[b]]] == 0)
            ma.erase(cost[ind[b]]);

//        for (auto &j : ma){
//            cout << j.first << " " << j.second << " ";
//        }
//        cout << "\n";

        cost[ind[a]] = nca;
        cost[ind[b]] = ncb;

        cout << ma.begin()->first << "\n";
    }
}