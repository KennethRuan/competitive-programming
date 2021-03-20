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
typedef pair<int,int> pii;

const int mxn = 1e5+5;
const int mod = 1e6+7;
const int logn = 17;

int n, m, bx[mxn], by[mxn], wx[mxn], wy[mxn];

void solve(){
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> bx[i] >> by[i];
    }
    for (int i = 0; i < m; i++){
        cin >> wx[i] >> wy[i];
    }
    sort(bx, bx+n);
    sort(by, by+n);
    sort(wx, wx+m);
    sort(wy, wy+m);
    int i = 0, j = 0, mn = INT_MAX;
    while (i < n && j < m){
        int diff = abs(bx[i] - wx[j]);
        mn = min(mn, diff);
        if (bx[i] < wx[j])
            i++;
        else
            j++;
    }
    while (i < n){
        int diff = abs(bx[i] - wx[j-1]);
        mn = min(mn, diff);
        i++;
    }
    while (j < m){
        int diff = abs(bx[i-1] - wx[j]);
        mn = min(mn, diff);
        j++;
    }

    i = 0, j = 0;
    while (i < n && j < m){
        int diff = abs(by[i] - wy[j]);
        mn = min(mn, diff);
        if (by[i] < wy[j])
            i++;
        else
            j++;
    }
    while (i < n){
        int diff = abs(by[i] - wy[j-1]);
        mn = min(mn, diff);
        i++;
    }
    while (j < m){
        int diff = abs(by[i-1] - wy[j]);
        mn = min(mn, diff);
        j++;
    }
    cout << mn;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}