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
ll n;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n <= 2){
        cout << 1;
        return 0;
    }
    ll x = 2;
    ll d = 3;
    for (int i = 2; i < 1e6; i++){
        x += d;
        if (i % 2 == 1)
            d += 2;
        if (n <= x){
            cout << i;
            break;
        }
    }
}