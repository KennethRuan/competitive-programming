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

const int mxn = 1e5+5;
const int mod = 1e9+7;

ll n, q, f[mxn];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(f, 0, sizeof(f));
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        ll x;
        cin >> x;
        f[x]++;
    }
    for (int i = 0; i < q; i++){
        ll op, x;
        cin >> op >> x;
        if (op == 1){
            ll h = (int) ceil(((double) x)/2);
            ll l = (int) floor(((double) x)/2);
            f[h]+=f[x];
            f[l]+=f[x];
            f[x]=0;
        }
        if (op == 2){
            cout << f[x] << "\n";
        }
    }
}