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
const ll LLM = 9999999999;


ll n,a;
double v,b,c;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> a >> b >> c;
    if (a == 0){
        for (int i = 0; i < n; i++)
            cout << "elastic\n";
    }
    else if (b > 0 && c > 0) {
        v = (c / (2.0 * b));
        for (int i = 0; i < n; i++) {
            ll p;
            cin >> p;
            if (p < v) {
                cout << "inelastic\n";
            } else {
                cout << "elastic\n";
            }
        }
    }
    else if (c > 0){
        for (int i = 0; i < n; i++)
            cout << "inelastic\n";
    }
    else{
        for (int i = 0; i < n; i++)
            cout << "elastic\n";
    }
}