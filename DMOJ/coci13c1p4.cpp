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

const int mxn = 3e5+5;
const int mxm = 1e5+5;
const int mod = 1e9+7;
const int logn = 17;

int n, k;
vector<pii> vm (mxn, {0,0}); //value, mass
multiset<int> c;

bool cpii(pii a, pii b){
    return a.first > b.first;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        int m, v;
        cin >> m >> v;
        vm[i] = {v,m};
    }
    for (int i = 0; i < k; i++){
        int  x;
        cin >> x;
        c.insert(x);
    }
    sort(vm.begin(), vm.begin()+n, cpii);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        auto it = c.lower_bound(vm[i].second);
        if (it == c.end())
            continue;
        c.erase(it);
        ans += vm[i].first;
    }
    cout << ans;
    return 0;
}