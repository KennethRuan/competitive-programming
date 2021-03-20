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
ll n, ans = 1, cnt = 0;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    ll msf = 0;
    cin >> msf;
    for (ll i = 1; i < n; i++){
        ll x;
        cin >> x;
        if (x >= msf){
            msf = x;
            ans = (ans*(2+cnt)) % mod;
            cnt = 0;
        }
        else cnt++;
    }
    cout << ans;
}