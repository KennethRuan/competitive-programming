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
ll n;
string al, s;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<char> l;
    set<string> ans;
    cin >> al >> s;
    for (char c: al){
        l.push_back(c);
    }
    for (int i = 0; i < s.length(); i++){
        string a = s;
        for (char c: l) {
            a = s;
            a[i] = c;
            ans.insert(a);
            a = s;
            a.insert(i, 1, c);
            ans.insert(a);
        }
        a = s;
        a.erase(a.begin()+i);
        ans.insert(a);
    }

    for (char c: l){
        string a = s;
        a.append(1, c);
        ans.insert(a);
    }
    for (auto &i : ans){
        if (i == s) continue;
        cout << i << "\n";
    }
}